// in this question we will have to topological sorting basically we will visit all the node the node from where we can't visit anywhere we will have to add it to the stack
public:

    void dfs(vector<int> adj[],vector<bool> &visited,int src,stack<int> &pp)
    {
        visited[src] = true;
        
        for(int i=0;i<adj[src].size();i++)
        {
            if(visited[adj[src][i]] == false)
            {
                dfs(adj,visited,adj[src][i],pp);
            }
        }
        // last node which is not dependent on any another node of all of it neighbour are already visited 
        pp.push(src);
    }

	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<bool> visited(V,false);
        stack<int> pp;
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                dfs(adj,visited,i,pp);
            }
        }

        while(pp.empty() == false)
        {
            int a = pp.top();
            pp.pop();
            ans.push_back(a);
        }

        return ans;
	}
};
