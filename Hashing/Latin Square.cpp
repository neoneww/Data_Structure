bool solve(vector<vector<string>>& matrix) {
    unordered_map<string, vector<pair<int, int>>> temp;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            temp[matrix[i][j]].push_back(make_pair(i, j));
        }
    }
    if (temp.size() != matrix.size()) return false;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            vector<pair<int, int>> qq;
            qq = temp[matrix[i][j]];
            for (int k = 0; k < qq.size(); k++) {
                pair<int, int> a = qq[k];
                if (a.first == i && a.second != j || a.first != i && a.second == j) return false;
            }
        }
    }

    return true;
}
