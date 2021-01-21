/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int returnSum(Tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->val + returnSum(root->left) + returnSum(root->right);
}

Tree* solve(Tree* root) {
    if(root == NULL)
    {
        return root;
    }
    int a = returnSum(root->left);
    int b = returnSum(root->right);
    root->val += a+b;
    solve(root->left);
    solve(root->right);
    return root;
    
}
