class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
         if(root == NULL)
         {
             return root;
         }
         else if(root->left == NULL && root->right == NULL)
         {
             return root;
         }
         else if(root->left != NULL && root->right ==NULL)
         {
             root->right = root->left;
             root->left = NULL;
             invertTree(root->right);
         }
         else if(root->right != NULL && root->left ==NULL)
         {
             root->left = root->right;
             root->right = NULL;
             invertTree(root->left);
         }
         else{
            TreeNode *a = root->left;
             root->left = root->right;
             root->right = a;
             invertTree(root->left);
             invertTree(root->right);
         }
        return root;
        
    }
};
