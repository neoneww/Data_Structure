int solve(vector<int>& nums, int target)
{
    int cnt = 0;
    unordered_map<int,int> pp;
    pp[nums[0]]++;
    for(int i=1;i<nums.size();i++)
    {
        if(pp.find(target-nums[i]) != pp.end() && pp[target-nums[i]] > 0)
        {
            pp[target-nums[i]]--;
            cnt++;
        }
        else
        {
            pp[nums[i]]++;
        }
    }

    return cnt;
}
