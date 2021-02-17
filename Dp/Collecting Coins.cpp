int solve(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    int dp[n][m];
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = matrix[0][0];

    for(int i=1;i<n;i++)
    {
        dp[i][0] = (dp[i-1][0] + matrix[i][0]);
    }

    for(int i=1;i<m;i++)
    {
        dp[0][i] = dp[0][i-1] + matrix[0][i];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j] = matrix[i][j] + max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n-1][m-1];


}

//basicallly this problem is equal to the max path sum in a matrix 
// we can only move right and down so in our dp matrix we will have top row of the matrix sum of the previous element 
//top to bottom coulmn as the sum of all previous element 
