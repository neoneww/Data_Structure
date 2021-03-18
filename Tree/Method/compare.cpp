/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void pre(Tree *root,vector<int> &arr)
{
    if(root == NULL)
    {
        return;
    }
    postOder(root->left,arr);
    if(root->left == NULL && root->right == NULL)
    {
        arr.push_back(root->val);
    }
    postOder(root->right,arr);
}

bool solve(Tree* root0, Tree* root1)
{
    if(root0 == NULL && root1 == NULL)
    {
        return true;
    }
    if(root0 == NULL && root1 != NULL || root0 != NULL && root1 == NULL)
    {
        return false;
    }
    vector<int> arr,brr;
    pre(root0,arr);
    pre(root1,brr);
    if(arr.size() != brr.size())
    {
        return false;
    }

    for(int i=0;i<arr.size();i++)
    {
       // cout<<arr[i]<<brr[i]<<"\n";
        if(arr[i] != brr[i])
        {
            return false;
        }
    }

    return true;
}
