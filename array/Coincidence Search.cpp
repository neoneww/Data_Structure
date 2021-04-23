int solve(vector<int>& nums) {
    int cnt = 0;

    for(int i=0;i<nums.size();i++)
    {
        int target = nums[i];

        int low=0,high=nums.size()-1;

        while(low<=high)
        {
            int mid=floor((low+high)/2);
            if(nums[mid] == target)
            {
                cnt++;
                break;
            }
            else if(nums[mid] < target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }

    return cnt;
}

// nlogn time complexity 
