long long minCost(long long arr[], long long n) {
    priority_queue<long long,vector<long long>,greater<long long>> pp;  // min heap
    for(long long i=0;i<n;i++)
    {
        pp.push(arr[i]);
    }
    long long cost = 0;
    while(pp.size() > 1)
    {
        long long a = pp.top();
        pp.pop();
        long long b = pp.top();
        pp.pop();
        long long ans = a+b;
        cost+=(a+b);
        pp.push(ans);
    }

    return cost;
}

// here we have to find the minimum cost to  merget the stone
