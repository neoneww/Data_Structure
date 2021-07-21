//keep going right and keep adding the left node;
vector<int> diagonalTraversal(TreeNode<int> *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    
    while(pendingNode.empty() == false){
        int cnt = pendingNode.size();
        while(cnt--){
            TreeNode<int>* front = pendingNode.front();
            pendingNode.pop();
            while(front != NULL){
                ans.push_back(front->data);
                if(front->left != NULL){
                    pendingNode.push(front->left);
                }
                front = front->right;
            }
        }
    }
    return ans;
}
