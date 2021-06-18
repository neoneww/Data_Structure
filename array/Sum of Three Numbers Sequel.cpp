int solve(vector<int>& nums, int val) {
    sort(nums.begin(), nums.end());
    int ans1 = INT_MAX, ans2 = INT_MIN;
    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] >= val) {
                ans1 = min(ans1, nums[i] + nums[j] + nums[k]);
                k--;
            } else {
                ans2 = max(ans2, nums[i] + nums[j] + nums[k]);
                j++;
            }
        }
    }

    if (ans1 == INT_MAX) return abs(ans2 - val);
    if (ans2 == INT_MIN) return abs(ans1 - val);

    return min(abs(ans2 - val), abs(ans1 - val));
}
