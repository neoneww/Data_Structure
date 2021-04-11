int solve(int n) {
    int a = 1,b=1;
    if(n==1 || n ==2)
    {
        return 1;
    }
    if(n==3)
    {
        return a+b;
    }
    int ans = 0;
    for(int i=3;i<=n;i++)
    {
        ans = a+b;
        a = b;
        b = ans;
    }

    return ans;
}
