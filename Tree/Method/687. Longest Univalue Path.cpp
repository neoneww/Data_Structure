class Solution {
public:
    int ans = 0;
    int dfs(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftPath = dfs(root->left);
        int rightPath = dfs(root->right);
        int leftCheck = 0;
        int rightCheck = 0;
        if(root->left != NULL && root->val == root->left->val)
        {
            leftCheck += leftPath + 1;
        }
        if(root->right != NULL && root->val == root->right->val)
        {
            rightCheck += rightPath + 1;
        }
        ans = max(ans,leftCheck+rightCheck);
        return max(leftCheck,rightCheck);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
