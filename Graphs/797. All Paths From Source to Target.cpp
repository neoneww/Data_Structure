class Solution {
public:

    vector<vector<int>> finAns;
    void dfs(vector<vector<int>> adj,vector<bool> &visited,int src,int dest,vector<int> ans)
    {
        if(src == dest)
        {
            ans.push_back(src);
            finAns.push_back(ans);
            return;
        }

        ans.push_back(src);
        visited[src] = true;
        for(int i=0;i<adj[src].size();i++)
        {
            dfs(adj,visited,adj[src][i],dest,ans);
        }
        visited[src] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        finAns.clear();
        vector<bool> visited;
        for(int i=0;i<graph.size();i++)
        {
            visited.push_back(false);
        }
        int n = graph.size()-1;
        vector<int> ans;
        dfs(graph,visited,0,n,ans);
        return finAns;
    }
};
