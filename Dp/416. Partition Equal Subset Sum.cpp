class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }

        if(sum%2 != 0)
        {
            return false;
        }
        int n = nums.size();
        int tar = (sum/2);
        bool dp[n+1][tar+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<tar+1;j++)
            {
                dp[i][j] = false;
            }
        }

        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = true;
        }

        for(int i=1;i<tar+1;i++)
        {
            dp[0][i] = false;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<tar+1;j++)
            {
                if(dp[i-1][j] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    int val = nums[i-1];
                    if(val <= j)
                    {
                        if(dp[i-1][j-val] == true)
                        {
                            dp[i][j] = true;
                        }
                    }
                }

            }
        }
        
        return dp[n][tar];
    }

};

// we need to find the sublist which give the sum k
