//we have to print if their is a path between two vertices

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
vector<vector<int>> solve(vector<vector<int>>& graph)
{
    vector<vector<int>> mat(graph.size(),vector<int>(graph.size(),0));
    for(int i=0;i<graph.size();i++)
    {
        vector<bool> visited(graph.size(),false);
        dfs(graph,visited,i);

        for(int j=0;j<visited.size();j++)
        {
            if(visited[j])
            {
                mat[i][j] = 1;
                mat[j][i] = 1;
            }
        }
    }
    return mat;
}
