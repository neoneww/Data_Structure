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
//first we will try to find the height of the binary tree
    int returnHeight(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return 1 + max(returnHeight(root->left),returnHeight(root->right));
    }
    int findsum(TreeNode *root,int k)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(k==1)
        {
            return root->val;
        }
        return findsum(root->left,k-1) + findsum(root->right,k-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = returnHeight(root);/**
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
//first we will try to find the height of the binary tree
    int returnHeight(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return 1 + max(returnHeight(root->left),returnHeight(root->right));
    }
    int findsum(TreeNode *root,int k)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(k==1)
        {
            return root->val;
        }
        return findsum(root->left,k-1) + findsum(root->right,k-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = returnHeight(root);
        height-1;
        return findsum(root,height);
    }
};
        return findsum(root,height);
    }
};
