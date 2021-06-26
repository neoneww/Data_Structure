void solve(Node *root,vector<vector<int>> &ans,vector<int> &smallAns)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        smallAns.push_back(root->data);
        ans.push_back(smallAns);
        smallAns.pop_back();

        return;
    }

    smallAns.push_back(root->data);
    solve(root->left, ans, smallAns);
    solve(root->right, ans, smallAns);
    smallAns.pop_back();
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root,ans,temp);
    return ans;
}
