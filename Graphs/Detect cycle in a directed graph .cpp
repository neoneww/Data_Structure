
public:
    bool detectCycle(vector<int> adj[],vector<bool> &visited,vector<bool> &ancestor,int src)
    {
        visited[src] = true;
        ancestor[src] = true;

        for(int i=0;i<adj[src].size();i++)
        {
            if(visited[adj[src][i]] == false)
            {
                if(detectCycle(adj,visited,ancestor,adj[src][i]))
                {
                    return true;
                }
            }else if(visited[adj[src][i]] == true)
            {
                if(ancestor[adj[src][i]] == true)
                {
                    return true;
                }
            }
        }
        ancestor[src] = false;
        return false;
    }

	bool isCyclic(int V, vector<int> adj[]) {
	   	vector<bool> visited(V,false);
        vector<bool> ancestor(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                if(detectCycle(adj,visited,ancestor,i))
                {
                    return true;
                }
            }
        }

        return false;
	}
};
