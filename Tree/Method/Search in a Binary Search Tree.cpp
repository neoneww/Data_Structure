/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root, int val) {
    if(root == NULL)
    {
        return false;
    }
    if(root->val > val)
    {
        return solve(root->left,val);
    }
    else if(root->val < val)
    {
        return solve(root->right,val);
    }

    return true;
}
