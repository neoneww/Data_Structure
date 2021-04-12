
int sum(int n)
{
    int ans = 0;
    while(n != 0)
    {
        ans += (n%10)*(n%10);
        n = n/10;
    }

    return ans;
}

bool solve(int n) {
    unordered_map<int,int> temp;
    int a = n;
    while(n != 1)
    {
        //cout<<n<<"\n";
        temp[n]++;
        if(temp[n] > 1)
        {
            break;
        }

        n = sum(n);
    }
    if(n == 1)
    {
        return true;
    }

    return false;
}
