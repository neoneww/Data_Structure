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
    int finalAns = INT_MIN;
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        dfs(root,root->val,root->val);
        return finalAns;
    }
    void dfs(TreeNode *root,int high,int low)
    {
        if(root == NULL)
        {
            return ;
        }
        if(root->val > high)
        {
            high = root->val;
        }
        if(root->val < low)
        {
            low = root->val;
        }
        if(abs(high-low) > finalAns)
        {
            finalAns = abs(high-low);
        }
        dfs(root->left,high,low);
        dfs(root->right,high,low);
    }
};
