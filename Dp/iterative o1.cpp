#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int value[n];
    int weight[n];

    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    int cap;

    cin>>cap;

    int dp[n+1][cap+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<cap+1;j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<cap+1;j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j >= weight[i-1])
            {
                if(dp[i-1][j-weight[i-1]] + value[i-1] > dp[i][j])
                {
                    dp[i][j] = dp[i-1][j-weight[i-1]] + value[i-1];
                }
            }
        }
    }

    cout << dp[n][cap]<<endl;
}
