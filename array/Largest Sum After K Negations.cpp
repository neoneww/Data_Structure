int solve(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int i = 0;
    while(k>0)
    {
        if(nums[i] < 0)
        {
            nums[i] = abs(nums[i]);
            k--;
            i++;
        }

        else if(nums[i] >= 0)
        {
            sort(nums.begin(),nums.end());
            if(k%2 != 0)
            {
                nums[0] = nums[0] * -1;
            }
            break;
        }
    }

    int sum = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }

    return sum;
}
