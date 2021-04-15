bool solve(vector<int>& nums) {
    if(nums.size() <= 1)
    {
        return true;
    }

    sort(nums.begin(),nums.end());
    int as = nums[1]-nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(as != nums[i]-nums[i-1])
        {
            return false;
        }
    }

    return true;
}
