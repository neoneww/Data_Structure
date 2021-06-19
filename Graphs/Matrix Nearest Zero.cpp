vector<vector<int>> solve(vector<vector<int>>& matrix) {
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    queue<pair<int, int>> pendingCells;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {  // marking all the source as visited
                visited[i][j] = true;
                pendingCells.push(make_pair(i, j));
            }
        }
    }
    vector<pair<int, int>> step = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dist = 0;
    while (pendingCells.empty() == false) {
        int cnt = pendingCells.size();
        while (cnt--) {
            pair<int, int> a = pendingCells.front();
            matrix[a.first][a.second] = dist;
            pendingCells.pop();
            for (int i = 0; i < step.size(); i++) {
                int x = a.first + step[i].first;
                int y = a.second + step[i].second;
                if (x < 0 || x >= matrix.size() || y < 0 || y > matrix[0].size() || visited[x][y])
                    continue;
                pendingCells.push({x, y});
                visited[x][y] = true;
            }
        }
        dist++;
    }
    return matrix;
}
