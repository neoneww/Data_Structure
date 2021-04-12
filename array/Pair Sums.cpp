int solve(vector<int>& nums) {
    int odd=0,even=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]%2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    return even*odd;
}
