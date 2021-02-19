#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin>>n;

    int dp0[n+1];
    int dp1[n+1];

    for(int i=0;i<n+1;i++)
    {
        dp0[i] = 0;
        dp1[i] = 0;
    }

    dp0[1] = 1;
    dp1[1] = 1;

    for(int i=2;i<n+1;i++)
    {
        dp1[i] = dp1[i-1] + dp0[i-1];
        dp0[i] = dp1[i-1];
    }

    cout << (dp1[n] + dp0[n]) << endl;
}
