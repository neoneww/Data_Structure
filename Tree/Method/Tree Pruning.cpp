/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool check(Tree *root)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->val != 0)
    {
        return false;
    }

    return true && check(root->left) && check(root->right);
}



void solvee(Tree* root) {
    if(root == NULL)
    {
        return;
    }
    if(check(root->left) == true)
    {
        root->left = NULL;
    }
    if(check(root->right) == true)
    {
        root->right = NULL;
    }
    solvee(root->left);
    solvee(root->right);

}
Tree* solve(Tree* root)
{
    if(root == NULL)
    {
        return root;
    }
    solvee(root);
    return root;
}
// we will remove all the sub tree which will all contain all zero 
// we will make a function which will check left and right sub tree if it contains 1 we will send a false
// which means that we have to move on if a true came turn the left or right side to NULL
