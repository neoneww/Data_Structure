void width(TreeNode *root,int vl,vector<int> &minMax){
    if(root == NULL) return;

    minMax[0] = min(minMax[0],vl);
    minMax[1] = max(minMax[1],vl);

    width(root->left,vl-1,minMax);
    width(root->right,vl+1,minMax);
}


vector<int> TopView(TreeNode *root)
{
    vector<int> qq;
    if(root == NULL) return qq;
    vector<int> minMax(2);

    minMax[0] = INT_MAX;
    minMax[1] = INT_MIN;

    width(root,0,minMax);

    int siz = minMax[1] - minMax[0] + 1;
    vector<vector<int>> ans(siz);
    queue<pair<TreeNode*,int>> pendingNode;
    pendingNode.push({root,abs(minMax[0])});

    while(pendingNode.empty() == false){
        int cnt = pendingNode.size();
        while(cnt--){
            pair<TreeNode*,int> front = pendingNode.front();
            pendingNode.pop();
            ans[front.second].push_back(front.first->val);
            if(front.first->left != NULL){
                pendingNode.push({front.first->left,front.second-1});
            }
            if(front.first->right != NULL){
                pendingNode.push({front.first->right,front.second+1});
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        qq.push_back(ans[i][0]);
    }

    return qq;

}
