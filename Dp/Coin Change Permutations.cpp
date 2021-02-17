#include <iostream>
using namespace std;

int main()

{
    int n;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    int tar;
    cin>>tar;
    int dp[tar+1] = {0};
    dp[0] = 1;

    for(int i=1;i<=tar;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j] <= i)
            {
                dp[i] += dp[i-coins[j]];
            }
        }
    }

    cout << dp[tar] << endl;

}
