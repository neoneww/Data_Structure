vector<int> solve(vector<int>& nums)
{
    if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
    {
        return nums;
    }
    if(nums.size() == 3)
    {
        swap(nums[0],nums[2]);
        return nums;
    }
    int i=0,j=2,k=1,l=3;
    while(i < nums.size() && j < nums.size() || k < nums.size() && l < nums.size())
    {
        if(i<nums.size() && j<nums.size())
        {
            swap(nums[i],nums[j]);
        }
        if(k<nums.size() && l<nums.size())
        {
            swap(nums[k],nums[l]);
        }
        i+=4;j+=4;k+=4;l+=4;
    }

    return nums;
}
