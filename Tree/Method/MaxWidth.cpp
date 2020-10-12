int getMaxWidth(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    queue<Node*> maxWidth;
    
    int ans = 1;
    maxWidth.push(root);
    
    while (maxWidth.size() != 0)
    {
        int cnt = maxWidth.size();
        ans = max(ans,cnt);
        while(cnt--)
        {
            Node *front = maxWidth.front();
            maxWidth.pop();
            if(front->left != NULL)
            {
                maxWidth.push(front->left);
            }
            if(front->right != NULL)
            {
                maxWidth.push(front->right);
            }
        }
    }
    
    return ans;

}

