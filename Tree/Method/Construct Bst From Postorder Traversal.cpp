TreeNode *solve(vector<int> &preorder,int &idx,int low,int high){
    if(idx <= -1 || preorder[idx] < low || preorder[idx] > high) return NULL;
    TreeNode *root = new TreeNode(preorder[idx]);
    idx--;
    root->right = solve(preorder,idx,root->val,high);
    root->left = solve(preorder,idx,low,root->val);
    return root;
}

TreeNode *bstFromPostorder(vector<int> &preorder)
{
    int n = preorder.size()-1;
    return solve(preorder,n,-1e9,1e9);
}
