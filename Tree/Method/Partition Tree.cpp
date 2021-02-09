/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {

    vector<int> ans;
    if(root == NULL)
    {
        ans.push_back(0);
        ans.push_back(0);
        return ans;
    }
    int leafcnt = 0,internodecnt = 0;
    queue<Tree*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        while(cnt--)
        {
            Tree *front = pendingNode.front();
            pendingNode.pop();
            if(front->left == NULL && front->right == NULL)
            {
                leafcnt++;
            }
            else
            {
                internodecnt++;
            }
            if(front->left != NULL)
            {
                pendingNode.push(front->left);
            }
            if(front->right != NULL)
            {
                pendingNode.push(front->right);
            }
        }
        
    }
     ans.push_back(leafcnt);
        ans.push_back(internodecnt);
       return ans;
}
