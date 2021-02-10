/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */


int traverse(Tree *root,bool left)
{
    if(root == NULL)
    {
        return 0;
    }
    if(left == false)
    {
        return 1 + traverse(root->left,true);
    }

    return 1 + traverse(root->right,false);
}




int solve(Tree* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int b = 1 + traverse(root->left,true);
    int c = 1 + traverse(root->right,false);
 
    return max(b,max(c,max(solve(root->left),solve(root->right))));
}

// we have to find the longest zig zag path 
