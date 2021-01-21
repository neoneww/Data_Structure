/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
//inverting a binary tree

Tree* invertTree(Tree* root)
{
    if(root == NULL)
    {
        return root;
    }
    Tree* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

Tree* solve(Tree* root) {
    if(root == NULL)
    {
        return root;
    }
    return invertTree(root);
}
