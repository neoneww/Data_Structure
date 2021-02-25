#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;


bool dfs(vector<vector<int>> adj,int src,int dest,vector<bool> &visited)
{
    if(src == dest)
    {
        return true;
    }

    visited[src] = true;

    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]] == false)
        {
            bool haspath =  dfs(adj,adj[src][i],dest,visited);

            if(haspath == true)
            {
                return true;
            }
        }
    }
}

int main()
{
    int n,m; //n = no of vertices m = no of edges
    cin>>n>>m;
    vector<vector<int>> adj(n);  //adj list
    //m is no of edges
    //making an undirected graph 
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src,dest;
    cin>>src>>dest;

    if(src == dest)
    {
        cout<<"true"<<endl;
        return 0;
    }

    visited.clear();

    for(int i=0;i<n;i++)
    {
        visited.push_back(false);
    }

    bool ans = dfs(adj,src,dest,visited);

    if(ans)
    {
        cout<<"true";
    }else
    {
        cout<<"false";
    }
}
