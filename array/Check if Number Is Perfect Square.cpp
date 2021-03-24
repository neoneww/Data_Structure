bool solve(int n) {
    if(n <= 1)
    {
        return true;
    }
    int l = 1;
    int r = n/2;

    while(l <= r)
    {
        long long m = l + (r-l)/2;

        if(m*m == n)
        {
            return true;
        }
        else if(m*m < n)
        {
            l = m+1;
        }
        else 
        {
            r = m-1;
        }
    }
    return false;
}

//the thing we haveto see in this question the sqrt will lie btw 1 to n/2)
