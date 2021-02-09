/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void inorder(Tree *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

bool solve(Tree* root) {
    if(root == NULL)
    {
        return true;
    }
    vector<int> ans;
    inorder(root,ans);
    int i = 0,j = ans.size() - 1;
    while(i <= j)
    {
        if(ans[i] != ans[j])
        {
            return false;
        }
        i++;j--;
    }

    return true;
}
