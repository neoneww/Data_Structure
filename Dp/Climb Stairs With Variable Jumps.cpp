#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> num;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        num.push_back(a);  // we are storing the num of jump we can make to reach a particular stair 
    }

    vector<int> dp;
    for(int i=0;i<n+1;i++)
    {
        dp.push_back(0);
    }
    dp[n] = 1;  // no of ways to reach n from n is just 1 

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=num[i];j++)
        {
            if(i+j < dp.size())
            {
                dp[i] += dp[i+j];
            }
        }
    }

    cout << dp[0] << endl;

}
