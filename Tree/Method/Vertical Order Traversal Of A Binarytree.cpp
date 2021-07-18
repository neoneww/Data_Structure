void width(TreeNode *root,int vl,vector<int> &minMax){
    if(root == NULL) return;

    minMax[0] = min(minMax[0],vl);
    minMax[1] = max(minMax[1],vl);

    width(root->left,vl-1,minMax);
    width(root->right,vl+1,minMax);
}



vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    vector<int> minMax(2);

    minMax[0] = INT_MAX;
    minMax[1] = INT_MIN;

    width(root,0,minMax);

    int siz = minMax[1] - minMax[0] + 1;
    vector<vector<int>> anns(siz);
    queue<pair<TreeNode*,int>> pendingNode;
    pendingNode.push({root,abs(minMax[0])});

    while(pendingNode.empty() == false){
        int cnt = pendingNode.size();
        while(cnt--){
            pair<TreeNode*,int> front = pendingNode.front();
            pendingNode.pop();
            anns[front.second].push_back(front.first->val);
            if(front.first->left != NULL){
                pendingNode.push({front.first->left,front.second-1});
            }
            if(front.first->right != NULL){
                pendingNode.push({front.first->right,front.second+1});
            }
        }
    }

    return anns;

}
