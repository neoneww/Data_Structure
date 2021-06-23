// find the length of lcs and then find the sortest subsequence

int lcs(string &a, string &b, int n, int m, vector<vector<int>> &dp) {
    if (m == 0 || n == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    if (a[n - 1] == b[m - 1]) {
        return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1, dp);
    }

    return dp[n][m] = max(lcs(a, b, n - 1, m, dp), lcs(a, b, n, m - 1, dp));
}

int solve(string a, string b) {
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    lcs(a, b, n, m, dp);
    return dp[n][m] + (a.length() - dp[n][m]) + (b.length() - dp[n][m]);
}
