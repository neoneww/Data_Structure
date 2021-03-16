int solve(vector<int>& nums, int k)
{
    if(nums.size() == 0)
    {
        return -1;
    }
    int ans = -1;
    if(nums[0] <= k)
    {
        ans = 0;
    }
    for(int i=1;i<nums.size();i++)
    {
        nums[i]+=nums[i-1];
        if(nums[i] <= k)
        {
            ans = i;
        }
    }

    return ans;
}
