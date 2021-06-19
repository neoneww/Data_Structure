int solve(vector<int>& nums) {
    unordered_map<int, int> temp;
    int ans = 0, unique = 0;
    int i = 0, j = 0;
    while (j < nums.size()) {
        if (++temp[nums[j]] == 1) unique++;
        while (unique < j - i + 1) {
            if (--temp[nums[i++]] == 0) unique--;
        }
        ans = max(ans, unique);
        j++;
    }

    return ans;
}
