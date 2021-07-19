class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> pendingNode;
        pendingNode.push(root);

        while(pendingNode.empty() == false){
            int cnt = pendingNode.size();
            vector<int> temp;
            while(cnt--){
                Node *front = pendingNode.front();
                pendingNode.pop();
                temp.push_back(front->val);
                for(int i=0;i<front->children.size();i++){
                    pendingNode.push(front->children[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
