vector<vector<int>> solve(vector<vector<int>>& graph)
{
    vector<vector<int>> adj(graph.size());

    for(int i=0;i<graph.size();i++)
    {
        if(graph[i].size() != 0)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }
    }

    return adj;    
}   

// we will have a graph which will reverse 
