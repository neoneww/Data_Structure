int solve(Tree* root,int k)
{
    if(root == NULL)
    {
        return 0;
    }
    priority_queue<int> pp;
    queue<Tree*> pendingNode;
    pendingNode.push(root);
    pp.push(root->val);

    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        while(cnt--)
        {
            Tree *front = pendingNode.front();
            pendingNode.pop();

            if(front->right != NULL)
            {
                pendingNode.push(front->right);
                pp.push(front->right->val);
            }

            if(front->left != NULL)
            {
                pendingNode.push(front->left);
                pp.push(front->left->val);
            }
        }
    }
    while(pp.size() > k+1)
    {
        pp.pop();
    }
    int ans = pp.top();
    return ans;

}
