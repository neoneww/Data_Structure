#include <bits/stdc++.h>
using namespace std;

int n,m; // size of the room
char roomMap[1002][1002];
bool visited[1002][1002];


bool isValid(int x,int y)
{
    if(x < 0 || x > n-1 || y < 0 || y > m-1)
    {
        return false;
    }
    if(roomMap[x][y] == '#' || visited[x][y] == true)
    {
        return false;
    }
    return true;
}

void dfs(int x,int y){
    visited[x][y] = true;
    if(isValid(x-1,y))
    {
        dfs(x-1,y);
    }
    if(isValid(x+1,y))
    {
        dfs(x+1,y);
    }
    if(isValid(x,y-1))
    {
        dfs(x,y-1);
    }
    if(isValid(x,y+1))
    {
        dfs(x,y+1);
    }
    return;
}


int main(){
    int finalAns = 0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> roomMap[i][j];
            if(roomMap[i][j] == '#')
            {
                visited[i][j] = true;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j] == false)
            {
                finalAns++;
                dfs(i,j);
            }
        }
    }

    cout << finalAns << endl;

}
