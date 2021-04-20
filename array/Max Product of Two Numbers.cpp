int solve(vector<int>& nums) {
    int minval = nums[0], maxval = nums[0], ans = INT_MIN;
    for (int i = 1; i < nums.size(); i++) {
        ans = max(ans, max(minval * nums[i], maxval * nums[i]));
        minval = min(minval, nums[i]);
        maxval = max(maxval, nums[i]);
    }
    return ans;
}
