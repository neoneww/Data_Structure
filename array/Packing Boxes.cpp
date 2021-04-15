vector<vector<int>> solve(vector<int>& nums)
{
    vector<vector<int>> ans;
    if(nums.size() == 0)
    {
        return ans;
    }
    int i=1;
    vector<int> temp;
    temp.push_back(nums[0]);
    while(i<nums.size())
    {
        if(nums[i] == nums[i-1])
        {
            temp.push_back(nums[i]);
        }
        else
        {
            ans.push_back(temp);
            temp.clear();
            temp.push_back(nums[i]);
        }
        i++;
    }
    ans.push_back(temp);

    return ans; 
}
