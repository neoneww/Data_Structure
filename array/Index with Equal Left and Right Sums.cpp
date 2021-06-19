int solve(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    vector<int> pref = nums;
    // cout << pref[0] << " ";
    for (int i = 1; i < pref.size(); i++) {
        pref[i] += pref[i - 1];
        // cout << pref[i] << " ";
    }

    for (int i = 0; i < pref.size(); i++) {
        int a = pref[pref.size() - 1] - pref[i];
        int b = pref[i] - nums[i];
        if (a == b) return i;
    }

    return -1;
}
