int solve(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());

    int i =0,j=nums.size()-1;
    int ans = INT_MIN;


    while(i<j)
    {   
        int q = nums[i]+nums[j];
        if(target <= q)
        {
            j--;
        }
        else
        {
            ans = max(ans,q);
            i++;
        }
    }

    return ans;
}
