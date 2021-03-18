bool solve(vector<int>& nums, int k)
{
    if(nums.size() < 4)
    {
        return false;
    }
    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size()-1;i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            int tar = k - nums[i] - nums[j];
            int front = j + 1;
            int back = nums.size()-1;

            while(front < back)
            {
                int sum = nums[front] + nums[back];
                if(sum == tar)
                {
                    return true;
                }
                if(sum < tar)
                {
                    front++;
                }
                else
                {
                    back--;
                }
            }
        }
    }

    return false;
}
