int solve(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    int curr_max = nums[0] + 0;
    for (int i = 1; i < nums.size(); i++) {
        ans = max(ans, (curr_max + (nums[i] - i)));
        curr_max = max(nums[i] + i, curr_max);
    }
    return ans;
}
