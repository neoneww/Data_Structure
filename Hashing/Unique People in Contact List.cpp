int solve(vector<vector<string>>& contacts) {
    if (contacts.size() <= 1) {
        return contacts.size();
    }
    unordered_map<string, int> temp;
    int cnt = 1;
    for (int i = 0; i < contacts[0].size(); i++) {
        temp[contacts[0][i]]++;
    }
    for (int i = 1; i < contacts.size(); i++) {
        bool flag = true;
        for (int j = 0; j < contacts[i].size(); j++) {
            if (temp.find(contacts[i][j]) != temp.end()) {
                flag = false;
            }
        }
        for (int j = 0; j < contacts[i].size(); j++) {
            temp[contacts[i][j]]++;
        }
        if (flag) {
            cnt++;
        }
    }

    return cnt;
}
