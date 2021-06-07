int solve(int n) {
    int k = n / 2;
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        if (i * i == n) return i;

        if (i * i > n) {
            ans = i;
            break;
        }
    }

    if (ans == 0) return k + 1;

    return ans - 1;
}

// we just need to check till n/2
