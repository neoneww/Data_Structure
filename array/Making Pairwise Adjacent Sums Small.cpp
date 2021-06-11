int solve(vector<int>& nums, int k) {
    if (nums.size() < 2) return 0;
    int cnt = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] + nums[i + 1] > k) {
            int temp = k - (nums[i] + nums[i + 1]);
            if (nums[i + 1] < abs(temp)) {
                cnt += abs(temp);
                temp = abs(temp) - nums[i + 1];
                nums[i + 1] = 0;
                nums[i] -= temp;

            } else {
                nums[i + 1] -= abs(temp);
                cnt += abs(temp);
            }
            cnt = cnt % 1000000007;
        }
    }

    return cnt % 1000000007;
}
