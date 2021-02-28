bool solve(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1)
    {
        return true;
    }
    bool a = false;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i-1]<nums[i])
        {
            a = true;
        }
        else
        {
            a = false;
            break;
        }
    }
    if(a == false)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                a = true;
            }
            else
            {
                a = false;
                break;
            }
        }
    }

    return a;
}
