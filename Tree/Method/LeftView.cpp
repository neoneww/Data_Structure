vector<int> leftView(Node *root)
{
    vector<int> brr;
    if(root == NULL)
    {
        return brr;
    }
    brr.push_back(root->data);
    queue<Node*> pendingNodes;
    if(root->left != NULL)
    {
        // brr.push_back(root->left->data);
        pendingNodes.push(root->left);
    }
    if(root->right != NULL)
    {
        pendingNodes.push(root->right);
    }
    while(pendingNodes.size() != 0)
    {
        int cnt = pendingNodes.size();
        Node *first = pendingNodes.front();
        brr.push_back(first->data);
        while(cnt--)
        {
            if(first->left != NULL)
            {
                pendingNodes.push(first->left);
            }
            if(first->right != NULL)
            {
                pendingNodes.push(first->right);
            }
            pendingNodes.pop();
        }
    }
    return brr;
}
