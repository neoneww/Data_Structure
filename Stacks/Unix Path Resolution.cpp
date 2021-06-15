vector<string> solve(vector<string>& path) {
    vector<string> ans;
    stack<string> temp;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == ".." && temp.empty() == false) {
            temp.pop();
        } else if (path[i] != ".." && path[i] != ".") {
            temp.push(path[i]);
        }
    }
    while (temp.empty() == false) {
        string aq = temp.top();
        temp.pop();
        ans.push_back(aq);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// "." -> this means go back to previous folder
// ".." -> this means stay in current folder
