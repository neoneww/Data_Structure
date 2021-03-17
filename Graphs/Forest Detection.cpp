bool finAns =  true;

void detectCycle(vector<vector<int>> &adj,vector<bool> &visited,int src,int par)
{
    visited[src] = true;

    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]] == false)
        {
            detectCycle(adj,visited,adj[src][i],src);
        }
        else if(adj[src][i] != par)
        {
            finAns = false;
        }
    }
}


bool solve(vector<vector<int>>& edges)
{
    if(edges.size() == 0)
    {
        return true;
    }
    finAns =  true;
    int siz = INT_MIN;
    for(int i=0;i<edges.size();i++)
    {
        siz = max(siz,max(edges[i][0],edges[i][1]));
    }
    siz++;

    vector<vector<int>> adj(siz);
    vector<bool> visited(siz,false);
    vector<int> parent(siz,-1);

    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }    

    for(int i=0;i<siz;i++)
    {
        if(visited[i] == false)
        {
            detectCycle(adj,visited,i,-1);
        }
    }

    return finAns;

}
