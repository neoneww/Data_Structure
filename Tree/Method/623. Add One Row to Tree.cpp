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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        if(depth == 1) {
            TreeNode *aa = new TreeNode(val);
            aa->left = root;
            return aa;
        }
        int lev = 1;

        while(pendingNode.empty() == false){
            int cnt = pendingNode.size();
            if(lev == depth-1){
                while(pendingNode.size() != 0){
                    TreeNode *front = pendingNode.front();
                    pendingNode.pop();
                    TreeNode *nn = new TreeNode(val);
                    TreeNode *a = front->left;
                    TreeNode *b = front->right;
                    front->left = nn;
                    nn->left = a;
                    TreeNode *nr = new TreeNode(val);
                    front->right = nr;
                    nr->right = b;
                }
                break;
            }else{
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

            lev++;
        }
        return root;       
    }
};
