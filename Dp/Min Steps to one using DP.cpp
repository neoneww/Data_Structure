
vector<int> dp;

int solve(int n)
{
    if(n <= 1)
    {
        return 0;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    int op1 = INT_MAX;
    int op2 = INT_MAX;

    if(n%2 == 0)
    {
        op1 = solve(n/2);
    }
    if(n%3 == 0)
    {
        op2 = solve(n/3);
    }  

    return dp[n] = 1 + min(solve(n-1),min(op1,op2));
}

int countStepsToOne(int n)
{
    for(int i=0;i<=n+1;i++)
    {
        dp.push_back(-1);
    }

    return solve(n);
}

// minimum step to reach one 
// we can do n = n-1, n = n/2, n = n/3;
