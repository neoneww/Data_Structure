#include <bits/stdc++.h>
using namespace std;

int josep(int n,int k)
{
    if(n == 1)
        return 0;
    int a = josep(n-1,k);
    int ans = (a+k)%n;

    return ans;
}

int main()
{
    int n,k;
    cin >> n >> k;
    
    cout<<josep(n,k)<<"\n";
}
