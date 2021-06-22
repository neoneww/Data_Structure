int lcs3(string &a, string &b, string &c, int n, int m, int l, vector<vector<vector<int>>> &dp) {
    if (n == 0 || m == 0 || l == 0) return 0;
    if (dp[n][m][l] != -1) return dp[n][m][l];
    if (a[n - 1] == b[m - 1] && b[m - 1] == c[l - 1]) {
        return dp[n][m][l] = 1 + lcs3(a, b, c, n - 1, m - 1, l - 1, dp);
    }
    return dp[n][m][l] = max(lcs3(a, b, c, n - 1, m, l, dp),
                             max(lcs3(a, b, c, n, m - 1, l, dp), lcs3(a, b, c, n, m, l - 1, dp)));
}

int solve(string a, string b, string c) {
    int n = a.length(), m = b.length(), l = c.length();
    vector<vector<vector<int>>> dp(102, vector<vector<int>>(102, vector<int>(102, -1)));
    return lcs3(a, b, c, n, m, l, dp);
}
