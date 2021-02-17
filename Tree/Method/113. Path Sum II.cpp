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

// root to leaf path sum 

class Solution {
public:
    vector<vector<int>> ans;

    void pathSum(TreeNode *root,int k,vector<int> pp)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            k-=root->val;
            pp.push_back(root->val);
            if(k==0)
            {
                ans.push_back(pp);
            }
            return;
        }
        pp.push_back(root->val);
        pathSum(root->left,k-root->val,pp);
        pathSum(root->right,k-root->val,pp);
        return;
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if(root == NULL)
        {
            return ans;
        }
        vector<int> pp;
        pathSum(root,targetSum,pp);

        return ans;
    }
};
