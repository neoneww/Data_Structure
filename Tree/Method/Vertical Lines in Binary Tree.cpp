/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int ans(Tree *root)
{
    if(root == NULL) return 0;
    priority_queue<pair<Tree *,int>> pendingNode;
    unordered_set<int> pp;
    pendingNode.push({root,0});

    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        while(cnt--)
        {
            pair<Tree*,int> temp = pendingNode.top();
            pendingNode.pop();
            pp.insert(temp.second);

            if(temp.first->left != NULL)
            {
                pendingNode.push({temp.first->left,temp.second-1});
            }

            if(temp.first->right != NULL)
            {
                pendingNode.push({temp.first->right,temp.second+1});
            }
        }
    }

    return pp.size();
}

int solve(Tree* root) {
    return ans(root);
}
