/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool solve(Tree* root)
{
    if(root == NULL)
    {
        return true;
    }
    unordered_map<int,int> color;
    queue<Tree*> pendingNode;
    pendingNode.push(root);
    int odd=0,even=0;
    bool a=true,b=false;

    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        if(a)
        {
            odd+=cnt;
            a=false;
            b=true;
        }
        else
        {
            even+=cnt;
            b=false;
            a=true;
        }

        while(cnt--)
        {
            Tree *front = pendingNode.front();
            pendingNode.pop();

            color[front->val]++;

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
    vector<int> ans;
    for(auto i:color)
    {
        ans.push_back(i.second);
    }

    if(ans.size() == 1 && even == 0 || ans.size() == 1 && odd == 0)
    {
        return true;
    }

    sort(ans.begin(),ans.end());
    if(odd > even)
    {
        if(odd == ans[1] && even == ans[0])
        {
            return true;
        }
        
    }
    else
    {
        if(even == ans[1] && odd == ans[0])
        {
            return true;
        }
    }

    return false;
}
