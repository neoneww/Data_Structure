int solve(vector<int>& nums0, vector<int>& nums1, int k) {
    priority_queue<int> temp;
    for (int i = 0; i < nums0.size(); i++) {
        for (int j = 0; j < nums1.size(); j++) {
            temp.push(nums0[i] + nums1[j]);
        }
    }
    int ans = 0;
    while (k > 0) {
        ans += temp.top();
        temp.pop();
        k--;
    }
    return ans;
}
