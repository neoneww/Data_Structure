// my version -> pretty much same to soln
#include <bits/stdc++.h>
#define int long long 
using namespace std;


void dfs(vector<vector<int>> adj,vector<bool> &visited,int src)
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

int32_t main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(m+1)); // we have 1 to n vertices 
    vector<bool> visited(n+1,false);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> ans;

    for(int i=1;i<=n;i++)
    {
        if(visited[i] ==  false)
        {
            dfs(adj,visited,i);
            ans.push_back(i);
        }
    } 

    if(ans.size() <= 1)
    {
        cout<<0<<"\n";
    }
    else
    {
        cout<<ans.size()-1<<"\n";
        int u = ans[0];

        for(int i=1;i<ans.size();i++)
        {
            int v = ans[i];
            cout<<u<<" "<<v<<endl;
            u = v;
        }
    }
}

// correct one 
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
int cc = 0;
vector<vector<int>> g;
vector<bool> vis;
vector<int> lead;
 
void dfs(int u)
{
	vis[u] = true;
	for(auto v: g[u])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
}
 
void process_cc()
{
	for(auto i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			cc++;
			lead.push_back(i);
			dfs(i);
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	for(auto i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	process_cc();
 
	cout << cc-1 << endl;
	if(cc > 1 )
	{
		int u = lead[0]; int v;
		for(auto i = 1; i < cc; i++)
		{
			v = lead[i];
			cout << u << " " << v << endl;
			u = v;
		}
	}
}
