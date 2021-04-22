int solve(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;

    int l = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    int result = 0;

    while (l < n - 2) {
        int first = nums[l];
        int m = l + 1;
        int h = n - 1;

        while (m < h) {
            int second = nums[m];
            int third = nums[h];

            int sum = first + second + third;
            if (sum < target) {
                result += (h - m);
                m++;
            } else {
                h--;
            }
        }

        l++;
    }
    return result;
}
