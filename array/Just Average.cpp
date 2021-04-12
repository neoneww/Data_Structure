bool solve(vector<int>& nums, int k)
{
    int sum = k*(nums.size()-1);
    int fsum = 0;
    for(int i=0;i<nums.size();i++)
    {
        fsum+=nums[i];
    }
    for(int i=0;i<nums.size();i++)
    {
        if(fsum-nums[i] == sum)
        {
            return true;
        }
    }

    return false;
}
