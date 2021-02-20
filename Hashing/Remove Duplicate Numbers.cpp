vector<int> solve(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }
    int curr = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (mp[nums[i]] == 1) {
            nums[curr] = nums[i];
            curr++;
        }
    }
    nums.resize(curr);
    return nums;
}
