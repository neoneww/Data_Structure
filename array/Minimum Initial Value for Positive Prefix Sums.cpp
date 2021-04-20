int solve(vector<int>& nums) {
    if(nums.size() == 0)
    {
        return 1;
    }
    for(int i=1;i<nums.size();i++)
    {
        nums[i]+=nums[i-1];
    }
    bool a =false;
    int ans = INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] <= 0)
        {
            a = true;
        }
        ans = min(ans,nums[i]);
    }
    if(a==false)
    {
        return 1;
    }
    return abs(ans)+1;
}
