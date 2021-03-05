//dijkstra algorithim implementing using inefficient approach 


vector<int> dijkstra(vector<vector<int>> g,int n,int src)
{
    vector<bool> pro(n,false); // processed nodes 
    vector<int> dis(n,INT_MAX);

    dis[src] = true;
    pro[src] = true;

    for(int i=0;i<n-1;i++)
    {
        int u = min(pro,dis,n); // we will get vertex with minimum dis
        pro[u] = true;

        for(int i=0;i<n;i++)
        {
            if(g[u][v] > 0)
            {
                if(dis[u]+g[u][v] < dis[v])
                {
                    dis[v] = dis[u] + g[u][v];
                }
            }
        }
    }

    return dis;
} 
