int solve(vector<int>& nums, int k) {
    k++;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - nums[i - 1] > 1) {
            int dif = nums[i] - nums[i - 1];
            dif--;
            if (dif >= k) {
                return nums[i-1] + k;
            } else {
                k -= dif;
            }
        }
    }
    return nums[nums.size() - 1] + k;
}
