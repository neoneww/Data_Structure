int solve(vector<int>& nums)
{
    if(nums.size() == 0 || nums.size() == 1)
    {
        return 0;
    } 
    unordered_map<int,int> pp;
    for(int i=0;i<nums.size();i++)
    {
        pp[nums[i]]++;
    }
    int finSum = 0;
    for(auto i:pp)
    {
        int ans = i.second;
        finSum += (((i.second*(i.second-1))/2));
    }

    return finSum;
}
//  no of pairs from n terms = n*(n-1)/2
