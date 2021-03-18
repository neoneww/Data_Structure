int solve(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    int cnt = 1;
    int i = 0;
    int last = -1;
    while(i < nums.size())
    {
        if(nums[i] > 0 && last != nums[i])
        {
            if(cnt != nums[i])
            {
                return cnt;
            }
            cnt++;
            last = nums[i];
        }
        i++;
    }

    return cnt;    
}
