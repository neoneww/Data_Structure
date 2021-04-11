bool solve(vector<int>& nums) {
    unordered_map<int,int> temp;
    for(int i=0;i<nums.size();i++)
    {
        temp[nums[i]]++;
    }
    for(auto i:temp)
    {
        if(i.second%2 != 0)
        {
            return false;
        }
    }

    return true;
}
