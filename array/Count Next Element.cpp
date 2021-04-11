int solve(vector<int>& nums) {
    unordered_set<int> temp;
    for(int i=0;i<nums.size();i++)
    {
        temp.insert(nums[i]);
    }
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        if(temp.find(nums[i]+1) != temp.end())
        {
            ans++;
        }
    }
    return ans;
}
