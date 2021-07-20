/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    void pre(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &temp)
    {
        if(root == NULL) return;
        temp[root] = new TreeNode(root->val);
        pre(root->left,temp);
        pre(root->right,temp);
    }
    TreeNode * cloneTree(TreeNode * root) {
        if(root == NULL) return NULL;
    unordered_map<TreeNode*,TreeNode*> temp;
    pre(root,temp);
    queue<TreeNode*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.empty() == false){
        int cnt = pendingNode.size();
        while(cnt--){
            TreeNode *front = pendingNode.front();
            pendingNode.pop();
            temp[front]->left = temp[front->left];
            temp[front]->right = temp[front->right];
            if(front->left != NULL){
                pendingNode.push(front->left);
            }
            if(front->right != NULL){
                pendingNode.push(front->right);
            }
        }
    }
    return temp[root];
    }
};
