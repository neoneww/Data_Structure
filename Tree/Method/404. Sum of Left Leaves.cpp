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
// sum of all left leaves
class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        dfs(root,NULL);
        return ans;
    }

    void dfs(TreeNode *root,TreeNode *parent)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            if(parent != NULL && parent->left == root)
            {
                ans += root->val;
            }
        }
        dfs(root->left,root);
        dfs(root->right,root);
    }
};
