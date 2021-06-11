vector<vector<int>> solve(vector<vector<int>>& matrix) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> temp;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i - j].push(matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = temp[i - j].top();
            temp[i - j].pop();
        }
    }

    return matrix;
}
//  0   1  2
// 0[1, 4, 7],
// 1[2, 5, 8],
// 2[3, 6, 9]
