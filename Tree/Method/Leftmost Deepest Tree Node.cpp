/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int fin(Tree *root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + max(fin(root->left),fin(root->right));
}

int solve(Tree* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return root->val;
    }

    int height = fin(root);

    queue<Tree*> pendingNode;
    pendingNode.push(root);
    int ans = 0;
    height--;
    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        
        while(cnt--)
        {
            Tree *front = pendingNode.front();
            pendingNode.pop();
            if(front->left != NULL)
            {
                pendingNode.push(front->left);
            }
            if(front->right != NULL)
            {
                pendingNode.push(front->right);
            }
        }
        height--;
        if(height == 0)
        {
            Tree *temp = pendingNode.front();
            ans = temp->val;
            break;
        }
    }

    return ans;
}
