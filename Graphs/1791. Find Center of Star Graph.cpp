class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ans = INT_MIN;
         for(int i=0;i<edges.size();i++)
        {
            ans = max(ans,max(edges[i][0],edges[i][1]));
        }
        vector<vector<int>> adj(ans+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int fin = 0;
        for(int i=1;i<(ans+1);i++)
        {
            if(adj[i].size() == (ans-1))
            {
                fin = i;
                break;
            }
        }
        return fin;
    }
};
