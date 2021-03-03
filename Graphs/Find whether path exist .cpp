public:
    void dfs(vector <vector <int>> &M,int x,int y,vector <vector <bool>>& vis,int n)
    {
        if(x>=n || x<0 || y>=n || y<0|| vis[x][y]==true || M[x][y]==0)
        return;
        vis[x][y]=true;
        dfs(M,x+1,y,vis,n);
        dfs(M,x-1,y,vis,n);
        dfs(M,x,y+1,vis,n);
        dfs(M,x,y-1,vis,n);
    }
bool is_Possible(vector <vector <int>> &M) {
    int n = M.size();
    vector <vector <bool>> vis(n,vector <bool>(n,false));
    int a,b,dx,dy;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[i][j]==1)
            {
                a=i;b=j;
            }
            else if(M[i][j]==2)
            {
                dx=i;dy=j;
            }
        }
    }
    dfs(M,a,b,vis,n);
    return vis[dx][dy];
}
};
