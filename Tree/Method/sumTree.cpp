/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
//return if root is sum of it children
bool solve(Tree* root) {
    if(root == NULL)
    {
        return true;
    }
    if(root->left != NULL && root->right != NULL)
    {
        if(root->val != (root->left->val+root->right->val))
        {
            return false;
        }
    }
    else if(root->left != NULL && root->right == NULL)
    {
        if(root->val != root->left->val)
        {
            return false;
        }
    }else if(root->right != NULL && root->left == NULL)
    {
        if(root->val != root->right->val)
        {
            return false;
        }
    }else if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return solve(root->left) && solve(root->right);
}
