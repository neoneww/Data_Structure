void width(TreeNode *root, int vl, vector<int> &minMax)
{
    if (root == NULL)
        return;

    minMax[0] = min(minMax[0], vl);
    minMax[1] = max(minMax[1], vl);

    width(root->left, vl - 1, minMax);
    width(root->right, vl + 1, minMax);
}

vector<vector<int>> bottomOrderVal(TreeNode *root){
    vector<int> minMax(2);
    minMax[0] = INT_MAX;
    minMax[1] = INT_MIN;

    width(root,0,minMax);

    vector<vector<int>> ans(minMax[1] - minMax[0] + 1);
    vector<int> temp(minMax[1] - minMax[0] + 1);

    queue<pair<TreeNode*,int>> pendingNode;
    int level = 0;
    pendingNode.push({root,abs(minMax[0])});

    while(pendingNode.empty() == false){
        int cnt = pendingNode.size();
        while(cnt--){
            pair<TreeNode*,int> front = pendingNode.front();
            pendingNode.pop();
            
            if(level > temp[front.second]){
                ans[front.second].clear();
                temp[front.second] = level;
            }

            ans[front.second].push_back(front.first->val);

            if(front.first->left != NULL){
                pendingNode.push({front.first->left,front.second-1});
            }

            if(front.first->right != NULL){
                pendingNode.push({front.first->right,front.second+1});
            }

        }
        level++;
    }

    return ans;

}
