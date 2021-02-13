#include <iostream>
using namespace std;

int main()
{
    int n; // n is no of rows 
    int m; // m is no of columns 

    cin>>n>>m;

    int grid[n][m];
    int dp[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    dp[0][0] = grid[0][0];

    for(int i=1;i<n;i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int j=1;j<m;j++)
    {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << dp[n-1][m-1] << endl;

}
