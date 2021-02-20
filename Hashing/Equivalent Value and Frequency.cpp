bool solve(vector<int>& nums) {
    unordered_map<int,int> pp;
    for(int i=0;i<nums.size();i++)
    {
        pp[nums[i]]++;
    }
    bool a = false;
    for(auto i:pp)
    {
        if(i.first == i.second)
        {
            a = true;
            break;
        }
    }

    return a;
}
