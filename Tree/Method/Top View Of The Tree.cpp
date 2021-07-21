/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>

void width(TreeNode<int> *root,vector<int> &minMax,int val){
    if(root == NULL) return;
    
    minMax[0] = min(minMax[0],val);
    minMax[1] = max(minMax[1],val);
    
    width(root->left,minMax,val-1);
    width(root->right,minMax,val+1);
}


vector<int> getTopView(TreeNode<int> *root) {
    vector<int> qq;
    if(root == NULL) return qq;
     vector<int> minMax(2);
    minMax[0] = INT_MAX;
    minMax[1] = INT_MIN;
    
    width(root,minMax,0);
    
    vector<int> ans(minMax[1] - minMax[0] + 1,-1);
    queue<pair<TreeNode<int>*,int>> pendingNode;
    pendingNode.push({root,abs(minMax[0])});
    
    while(pendingNode.empty() == false){
        int cnt = pendingNode.size();
        while(cnt--){
            pair<TreeNode<int> *,int> front = pendingNode.front();
            pendingNode.pop();
            if(ans[front.second] == -1){
                ans[front.second] = front.first->val;
            }
            if(front.first->left != NULL){
                pendingNode.push({front.first->left,front.second-1});
            }
            if(front.first->right != NULL){
                pendingNode.push({front.first->right,front.second+1});
            }
        }
    }
    return ans;
}























