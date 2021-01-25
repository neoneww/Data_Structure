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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
        {
            return root;
        }
        
        return ans(root) ? root : NULL;
    }

    bool ans(TreeNode *root)
    {
        if(root == NULL)
        {
            return false;
        }
        bool a = ans(root->left);
        bool b = ans(root->right);

        if(!a){
            root->left = NULL;
        }
        if(!b){
            root->right = NULL;
        }
        
        return root->val == 1 || a || b;
    }
};
