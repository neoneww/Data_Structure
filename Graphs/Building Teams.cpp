#include <bits/stdc++.h>
#define int long long
using namespace std;

bool dfs(vector<vector<int>> &adj,vector<bool> &visited,int src,int col,vector<int> &color)
{
    visited[src] = true;
    color[src] = col;

    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]] == false)
        {
            if(dfs(adj,visited,adj[src][i],1-col,color) == false)
            {
                return false;
            }
        }
        else if(visited[adj[src][i]] == true && color[adj[src][i]] == col)
        {
            return false;
        }
    }

    return true;
}

int32_t main()
{
    int n,m;
    cin >> n >> m;  // we have n friends and m friendships 
    
    vector<vector<int>> adj(n+1); //we have n friends 
    vector<bool> visited(n+1); 
    vector<int> color(n+1,-1);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            if(dfs(adj,visited,i,0,color) == false)
            {
                cout<<"IMPOSSIBLE"<<"\n";
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(color[i] == 0)
        {
            cout<<1<<" ";
        }
        else
        {
            cout<<2<<" ";
        }
    }
}
