/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

 set<int> pp;

void atSameLevel(Tree *root,int cnt)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        cnt++;
        pp.insert(cnt);
        return;
    }
    cnt++;
    atSameLevel(root->left,cnt);
    atSameLevel(root->right,cnt);

    return;
}

bool solve(Tree* root)
{
    if(root == NULL)
    {
        return true;
    }    
    pp.clear();
    atSameLevel(root,0);
    if(pp.size() > 1)
    {
        return false;
    }

    return true;
}
