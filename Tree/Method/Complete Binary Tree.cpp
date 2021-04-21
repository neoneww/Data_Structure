
bool solve(Tree* root)
{
    if(root == NULL)
    {
        return true;
    }
    queue<Tree*> pendingNode;
    pendingNode.push(root);
    bool temp = false;
    while(pendingNode.size() != 0)
    {
        int cnt = pendingNode.size();

        while(cnt--)
        {
            Tree *front = pendingNode.front();
            pendingNode.pop();

            if(front->left != NULL)
            {
                if(temp)
                {
                    return false;
                }

                pendingNode.push(front->left);
            }
            else{
                temp = true;
            }

            if(front->right != NULL)
            {
                if(temp)
                {
                    return false;
                }
                pendingNode.push(front->right);
            }
            else{
                temp = true;
            }
        }
    }

    return true;
}
