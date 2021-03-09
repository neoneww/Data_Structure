#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
vector<int> par;
vector<bool> vis;
 
void bfs()
{
	vis[1] = true;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v: g[u])
		{
			if(!vis[v])
			{
				vis[v] = true;
				par[v] = u;
				q.push(v);
			}
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
	par.resize(n+1);
	for(int i = 0; i<=n; ++i)
	{
		par[i] = -1;
	}
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
 
	if(par[n] == -1)
	{
		cout <<  "IMPOSSIBLE";
		return 0;
	}
 
 
	int candidate = n;
	stack<int> stk;
	while(candidate != -1)
	{
		stk.push(candidate);
		candidate = par[candidate];
	}
 
	cout << stk.size() << endl;
 
	while(!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
 
 }
