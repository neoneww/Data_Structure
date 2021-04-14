int solve(int n) {
    while(n >= 10)
    {
        int a = 0;
        while(n != 0)
        {
            int p = n%10;
            a+=p;
            n = n/10;
        }
        n = a;
    }

    return n;
}
