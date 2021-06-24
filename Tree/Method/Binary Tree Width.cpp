int solve(Tree* root) {
    queue<pair<Tree*, int>> pendingNode;
    int res = 0;
    pendingNode.push(make_pair(root, 0));
    while (pendingNode.empty() == false) {
        int cnt = pendingNode.size();
        int a = INT_MAX, b = INT_MIN;
        while (cnt--) {
            pair<Tree*, int> q = pendingNode.front();
            pendingNode.pop();
            a = min(a, q.second);
            b = max(b, q.second);
            if (q.first->left != NULL) {
                pendingNode.push(make_pair(q.first->left, 2 * q.second - 1));
            }
            if (q.first->right != NULL) {
                pendingNode.push(make_pair(q.first->right, 2 * q.second));
            }
        }
        res = max(res, b - a + 1);
    }
    return res;
}
