int solve(int n) {
    vector<long long> arr(n+1);
    arr[1] = 1;
    arr[2] = 2;
    for(long long i=3;i<n+1;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] = (arr[i]%1000000007);
    }

    return arr[n]%1000000007;
}

//we can either take 1 or 2 steps at a time we have to return  how many ways we have to reach n steps
// thought process -> 
// basically we have F(n) = F(n-2) + F(n-1);
// no of ways to reach n steps is no of ways to reach n-1 steps + 1 + no of ways to reach n-2 steps + 2
