
int maxLen(int arr[], int n)
{
    unordered_map<int,int> pp;
    int sum = 0;
    sum = arr[0];
    pp[arr[0]] = 0;
    int ans = 0;
    for(int i=1;i<n;i++)
    {
        sum+=arr[i];
        if(pp.find(sum) != pp.end() || sum == 0)
        {
            if(sum == 0)
            {
                ans = max(ans,i+1);
            }
            else
            {
                ans = max(ans,i-pp[sum]);
            }
        }
        else
        {
            pp[sum] = i;
        }
    }
    return ans;
}
// we have to find the longesst subaray with zero sum 
