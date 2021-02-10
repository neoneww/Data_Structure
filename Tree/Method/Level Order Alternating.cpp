/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root)
{
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }    
    queue<Tree*> pendingNode;
    pendingNode.push(root);
    ans.push_back(root->val);
    bool alter = true;
    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        vector<int> mid;
        while(cnt--)
        {
            Tree *front = pendingNode.front();
            pendingNode.pop();
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                    mid.push_back(front->right->val);
                }
                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                    mid.push_back(front->left->val);
                }
            
        }
        if(alter == true)
        {
            for(int i=0;i<mid.size();i++)
            {
                ans.push_back(mid[i]);
            }
            alter = false;
        }else if(alter == false)
        {
            int n = mid.size()-1;
            for(int i=n;i>=0;i--)
            {
                ans.push_back(mid[i]);
            }
            alter = true;
        }

    }

    return ans;

}
