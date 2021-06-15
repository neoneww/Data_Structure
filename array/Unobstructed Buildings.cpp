vector<int> solve(vector<int>& heights) {
    if (heights.size() == 0) return heights;
    vector<int> ans;
    if (heights.size() == 1) {
        ans.push_back(0);
        return ans;
    }
    ans.push_back(heights.size() - 1);
    int top = heights[heights.size() - 1];
    for (int i = heights.size() - 2; i >= 0; i--) {
        if (heights[i] > top) {
            ans.push_back(i);
            top = heights[i];
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
