//largest root to leaf sum 
int findSum(Tree *root,int *sum)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->val + max(findSum(root->left,sum),findSum(root->right,sum));
}

int solve(Tree* root) {
    if(root == NULL)
    {
        return 0;
    }   
    return root->val + max(findSum(root->left,0),findSum(root->right,0));
}
