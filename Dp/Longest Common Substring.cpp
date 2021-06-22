class Solution {
    public:
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    int lcs(string a, string b, int n, int m) {
        if (n == 0 || m == 0) return 0;
        if (dp[n][m] != 0) return dp[n][m];
        if (a[n - 1] == b[m - 1]) {
            return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1);
        }
        return dp[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
    }
    int longestCommonSubsequence(string a, string b) {
        dp.clear();
        int n = a.length(), m = b.length();
        return lcs(a, b, n, m);
    }
};
