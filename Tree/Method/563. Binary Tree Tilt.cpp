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
    int findTilt(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        tilt(root);
        int finalans = sum(root);
        return finalans;
    }

    int sum(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return root->val + sum(root->left) + sum(root->right);
    }

    void tilt(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        int a = abs(sum(root->left) - sum(root->right));
        root->val = a;
        tilt(root->left);
        tilt(root->right);
    }
};
