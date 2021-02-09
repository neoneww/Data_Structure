int solve(Tree* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int ans = 0;
    queue<Tree*> pendingNode;
    pendingNode.push(root);

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
                if(front->right->left == NULL && front->right->right == NULL)
                {
                    ans+= front->right->val;
                }
            }

            if(front->left != NULL)
            {
                pendingNode.push(front->left);
            }
        }
    }

    return ans;

}
