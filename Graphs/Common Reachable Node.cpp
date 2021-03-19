void dfs(vector<vector<int>> &adj,vector<bool> &visited,int src)
{
    visited[src] = true;
    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]] == false)
        {
            dfs(adj,visited,adj[src][i]);
        }
    }
}

bool solve(vector<vector<int>>& edges, int a, int b)
{
    int siz = INT_MIN;
    for(int i=0;i<edges.size();i++)
    {
        siz = max(siz,max(edges[i][0],edges[i][1]));

    }
    vector<vector<int>> adj(siz+1);
    cout<<visited.size()<<visited1.size()<<"\n";
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    dfs(adj,visited,a);
    dfs(adj,visited1,b);


    return false;
}
