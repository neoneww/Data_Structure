int solve(int num) {
    int sum=0;
    while(num != 0)
    {
        int temp = num%10;
        sum+=temp;
        num = num/10;
    }

    return sum;
}
