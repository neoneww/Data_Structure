#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums; // this array will hold like how many jumps we can make from the nth step
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    vector<int> dp;
    for(int i=0;i<n+1;i++)
    {
        dp.push_back(0);
    }
    dp[n] = 0; // no of moves we can make to reach nth stair from the nth stair 

    for(int i=n-1;i>=0;i--)
    {
        int ans = INT_MAX;
        for(int j=1;j<=nums[i];j++)
        {
            if(i+j < dp.size())
            {
                ans = min(ans,dp[i+j]);
            }
        }
        if(ans == INT_MAX)
            dp[i] = INT_MAX;
        else
            dp[i] = 1 + ans;
    }
    cout << dp[0] << endl;
}
