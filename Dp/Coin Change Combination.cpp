#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int total;
    cin>>total;
    int dp[total+1] = {0};

    dp[0] = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=arr[i];j<total+1;j++)
        {
            dp[j] += dp[j-arr[i]];
        }
    }

    cout << dp[total] <<endl;
}
