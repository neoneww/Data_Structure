/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root, vector<string>& moves)
{
    stack<Tree*> pp;
    for(int i=0;i<moves.size();i++)
    {
        if(moves[i] == "RIGHT")
        {
            pp.push(root);
            root = root->right;
        }
        else if(moves[i] == "LEFT")
        {
            pp.push(root);
            root = root->left;
        }
        else if(moves[i] == "UP")
        {
            Tree *temp = pp.top();
            pp.pop();
            root = temp;
        }
    }

    return root->val;    
}
