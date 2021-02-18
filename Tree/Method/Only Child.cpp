/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root) {
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL)
    {
        return 1 + solve(root->left) + solve(root->right);
    }

    return solve(root->left) + solve(root->right);
}
