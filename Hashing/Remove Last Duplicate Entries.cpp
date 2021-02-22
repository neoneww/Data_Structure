vector<int> solve(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int,int> pp;
    for(int i=0;i<nums.size();i++)
    {
        pp[nums[i]]++;
    }

    for(int i=0;i<nums.size();i++)
    {
        if(pp[nums[i]] > 0)
        {
            ans.push_back(nums[i]);
            pp[nums[i]]--;
        }
        if(pp[nums[i]] == 1)
        {
            pp[nums[i]] = 0;
        }
    }

    return ans;
}
