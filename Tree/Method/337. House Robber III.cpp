class Solution {
public:
    int helper(TreeNode *root,bool isRobbed)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(isRobbed == true)
        {
            return helper(root->left,false) + helper(root->right,false);
        }
        int rob = root->val + helper(root->left,true) + helper(root->right,true);
        int not_rob = helper(root->left,false) + helper(root->right,false);

        return max(rob,not_rob);
    }
    int rob(TreeNode* root) {
        return helper(root,false);
    }
};
