/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 // what we can do it is either find the height of the tree then we can find the sum 
 // it might happen we will happen multiple leaf at same height so we also need a map 
 //to find the max height of the tree 
 vector<int> pp;

int findHeight(Tree *root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + max(findHeight(root->left),findHeight(root->right));
}

void findSum(Tree *root,int height,int sum)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        height--;
        sum+=root->val;
        if(height == 0)
        {
            pp.push_back(sum);
        }
        return;
    }
    sum+=root->val;
    findSum(root->left,height-1,sum);
     findSum(root->right,height-1,sum);
     return;
}



int solve(Tree* root) {
    if(root == NULL)
    {
        return 0;
    }
    int height = findHeight(root);
    pp.clear();
    findSum(root,height,0);
    sort(pp.begin(),pp.end());
    return pp[pp.size()-1];
}
