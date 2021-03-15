int bfs(vector<vector<int>> &matrix)
{
    int n = matrix.size();int m = matrix[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    if(matrix[0][0] == 1)
    {
        return -1;
    }

    visited[0][0] = true;
    queue<pair<int,int>> pendingNode;
    pendingNode.push({0,0});

    int ans = 0;

    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        ans++;
        while(cnt--)
        {
            pair<int,int> temp;
            temp = pendingNode.front();
            pendingNode.pop();
            int x = temp.first;
            int y = temp.second;

            if(x == n-1 && y == m-1)
            {
                return ans;
            }

            if(x+1 < n && visited[x+1][y] == false && matrix[x+1][y] != 1)
            {
                visited[x+1][y] = true;
                pendingNode.push({x+1,y});
            }
            if(x-1 >= 0 && visited[x-1][y] == false && matrix[x-1][y] != 1)
            {
                visited[x-1][y] = true;
                pendingNode.push({x-1,y});
            }
            if(y+1 < m && visited[x][y+1] == false && matrix[x][y+1] != 1)
            {
                visited[x][y+1] = true;
                pendingNode.push({x,y+1});
            }
            if(y-1 >= 0 && visited[x][y-1] == false && matrix[x][y-1] != 1)
            {
                visited[x][y-1] = true;
                pendingNode.push({x,y-1});
            }
        }
    }

    return -1;

}

int solve(vector<vector<int>>& matrix)
{
    return bfs(matrix);
}
