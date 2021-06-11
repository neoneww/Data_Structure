bool solve(int n, vector<int>& seats) {
    if (n == 0) return true;

    if (seats.size() == 0) return false;
    if (seats.size() == 1 && seats[0] == 0) return true;

    if (seats[0] == 0 && seats[1] == 0) {
        seats[0] = 1;
        n--;
        if (n == 0) return true;
    }

    if (seats[seats.size() - 1] == 0 && seats[seats.size() - 2] == 0) {
        n--;
        seats[seats.size() - 1] = 1;
        if (n == 0) return true;
    }

    for (int i = 1; i < seats.size() - 1; i++) {
        if (n == 0) return true;
        if (seats[i] == 0 && seats[i + 1] == 0 && seats[i - 1] == 0) {
            n--;
            seats[i] = 1;
        }
    }
    if (n == 0) return true;

    return false;
}
