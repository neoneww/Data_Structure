int solve(int n)
{
    int coins = 0;
    while(n > 0)
    {
        if(n >= 25)
        {
            int a = n/25;
            coins += a;
            n-=(a*25);
        }
        if(n >= 10)
        {
            int a = n/10;
            coins += a;
            n-=(a*10);
        }
        if(n >= 5)
        {
            int a = n/5;
            coins+=a;
            n-=(a*5);
        }else
        {
            coins+=n;
            n=0;
        }
    }

    return coins;
}
