vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    stack<int> temp;
    if(root == NULL) return ans;
    queue<Node*> pendingNode;
    pendingNode.push(root);
    
    while(pendingNode.size() != 0){
        int cnt = pendingNode.size();
        while(cnt--){
            Node *front = pendingNode.front();
            pendingNode.pop();
            temp.push(front->data);
            if(front->right != NULL){
                pendingNode.push(front->right);
            }
            if(front->left != NULL){
                pendingNode.push(front->left);
            }
        }
    }
    
    while(temp.size() != 0){
        ans.push_back(temp.top());
        temp.pop();
    }
    return ans;
}
