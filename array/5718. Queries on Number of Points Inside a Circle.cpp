class Solution {
    public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int radius = queries[i][2];
            int cnt = 0;
            for (int i = 0; i < points.size(); i++) {
                if (pow(points[i][0] - a, 2) + pow(points[i][1] - b, 2) <= pow(radius, 2)) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }

        return cnt;
    }
};
