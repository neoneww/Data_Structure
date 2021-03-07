
bool dfs(vector<vector<int>> &adj,vector<int> &col,int src,int par)
{
    col[src] = par;
    for(int i=0;i<adj[src].size();i++)
    {
        if(col[adj[src][i]] == -1)
        {
            dfs(adj,col,adj[src][i],1-par);
        }
        else
        {
            if(col[adj[src][i]] == par)
            {
                return false;
            }
        }
    }

    return true;
}


bool solve(vector<vector<int>>& graph)
{
    vector<int> col(250,-1);
    int par = 0;

    return dfs(graph,col,0,par);
}
