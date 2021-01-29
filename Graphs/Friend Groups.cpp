
void dfs(int src,vector<vector<int>> &adj,vector<bool> &visited)
{
    visited[src] = true;
    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]] == false)
        {
            dfs(adj[src][i],adj,visited);
        }
    }

}

int solve(vector<vector<int>>& friends) {
    int cnt = 0;
    vector<bool> visited(251,false);
    for(int i=0;i<friends.size();i++)
    {

            if(visited[i] == false)
            {
                dfs(i,friends,visited);
                cnt++;
            }
    }
    
    return cnt;

}
