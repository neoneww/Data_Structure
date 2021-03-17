//multi source bfs 

int solve(vector<vector<int>>& matrix)
{
    if(matrix.size() == 0)
    {
        return 0;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    bool aa = false;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> pendingNode;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j] == 2)
            {
                pendingNode.push({i,j});
                visited[i][j] = true;
            }
            if(matrix[i][j] == 1)
            {
                aa = true;
            }
        }
    }

    if(pendingNode.empty() == true && aa == true)
    {
        return -1;
    }
    if(aa == false && pendingNode.empty() == true)
    {
        return 0;
    }

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

            if(x+1 < n && visited[x+1][y] == false && matrix[x+1][y] != 0)
            {
                pendingNode.push({x+1,y});
                visited[x+1][y] = true;
                matrix[x+1][y] = 2;
            }
            if(x-1 >= 0 && visited[x-1][y] == false && matrix[x-1][y] != 0)
            {
                pendingNode.push({x-1,y});
                visited[x-1][y] = true;
                matrix[x-1][y] = 2;
            }
            if(y+1 < m && visited[x][y+1] == false && matrix[x][y+1] != 0)
            {
                pendingNode.push({x,y+1});
                visited[x][y+1] = true;
                matrix[x][y+1] = 2;
            }
            if(y-1 >= 0 && visited[x][y-1] == false && matrix[x][y-1] != 0)
            {
                pendingNode.push({x,y-1});
                visited[x][y-1] = true;
                matrix[x][y-1] = 2;
            }

        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return ans-1;   
}


//0 is empty 1 is tree 2 is tree in fire 
