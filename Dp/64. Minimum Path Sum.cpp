class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        
        int n=v.size();
        int m=v[0].size();
        int dp[n][m];
        
        dp[0][0]=v[0][0];
        
        for(int i=1;i<n;i++)
        {
            dp[i][0]=dp[i-1][0]+v[i][0];
        }
        
        
        
        for(int i=1;i<m;i++)
        {
            dp[0][i]=dp[0][i-1]+v[0][i];
        }
        
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                    dp[i][j]=v[i][j] + min (dp[i-1][j] , dp[i][j-1]);
            }   
        }
    
        
        
        return dp[n-1][m-1];
        
        
    }
};
