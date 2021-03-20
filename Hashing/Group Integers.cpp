bool solve(vector<int>& nums)
{
    if(nums.size() < 2)
    {
        return false;
    }
    unordered_map<int,int> freq;
    unordered_map<int,int> oodd;
    for(int i=0;i<nums.size();i++)
    {
        freq[nums[i]]++;
    }
    int odd = 0,even = 0;
    int cnt = 0;
    int oddMax=0,evenMax=0;
    for(auto i:freq)
    {
        if(i.second%2 != 0 && i.second > 1)
        {
            cnt+=(i.second);
            odd++;
            oodd[i.second]++;
        }
        else if(i.second%2 == 0 && i.second > 1)
        {
            cnt+=(i.second);
            even++;
        }
    }

    if(oodd.size() > 1)
    {
        return false;
    }

    if(nums.size() - cnt> 0)
    {
        return false;
    }

    if(even > 0 && odd > 0)
    {
        return false;
    }

    return true;

}
