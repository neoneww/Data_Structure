/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int ans;
void dfs(Tree *root,int high,int low)
{
    if(root == NULL)
    {
        return;
    }
    high = max(root->val,high);
    low =  min(root->val,low);
    ans = max(ans,abs(high-low));
    dfs(root->left,high,low);
    dfs(root->right,high,low);
}

int solve(Tree* root)
{
    if(root == NULL)
    {
        return 0;
    }
    ans = INT_MIN;
    dfs(root,INT_MIN,INT_MAX);
    return ans;
}
