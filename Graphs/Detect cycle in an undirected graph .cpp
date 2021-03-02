public:
    //we will detect cycle in a undirected graph we will well check if node neighbour is already visited and not it's parent
    bool detectCycle(vector<int> adj[],vector<bool> &visited,int src,int par)
    {
        visited[src] = true;

        for(int i=0;i<adj[src].size();i++)
        {
            if(visited[adj[src][i]] == false)
            {
                if(detectCycle(adj,visited,adj[src][i],src))
                {
                    return true;
                }
            }
            else if(adj[src][i] != par)
            {
                return true;
            }
        }

        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                if(detectCycle(adj,visited,i,-1))
                {
                    return true;
                }
            }
        }
        return false;
	}
};
