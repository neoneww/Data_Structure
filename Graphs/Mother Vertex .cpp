public:
	//mother vertex is a vertex from which we can reach any other vertex 


void dfs(vector<int> adj[],vector<bool> &visited,int src)
{
    if(visited[src] == true)
    {
        return;
    }

    visited[src] = true;
    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]] == false)
        {
            dfs(adj,visited,adj[src][i]);
        }
    }
}

int findMotherVertex(int V, vector<int>adj[])
{   int last = 0;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
            last = i;
            dfs(adj,visited,i);
        }
    }
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
    }
    dfs(adj,visited,last);
    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
            return -1;
        }
    }

    return last;
}
