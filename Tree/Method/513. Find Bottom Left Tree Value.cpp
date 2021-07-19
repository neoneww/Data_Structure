/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        TreeNode *last;

        while(pendingNode.empty() == false){
            last = pendingNode.front();
            int cnt = pendingNode.size();
            while(cnt--){
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                if(front->left != NULL){
                    pendingNode.push(front->left);
                }
                if(front->right != NULL){
                    pendingNode.push(front->right);
                }
            }
        }

        return last->val;
    }
};
