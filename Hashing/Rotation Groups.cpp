string rotate(string s, int k) {
    string res = "";
    for (int i = k; i < s.size(); i++) {
        res += s[i];
    }
    for (int i = 0; i < k; i++) {
        res += s[i];
    }
    return res;
}
//idea is pretty simple generate all permutation and then assign same id to them and then 
//if the list contains same word we will just continue 
int solve(vector<string>& words) {
    unordered_map<string, int> f;
    int id = 0;
    for (string& s : words) {
        if (f.find(s) != f.end()) continue;
        for (int i = 0; i < s.size(); i++) {
            string rot = rotate(s, i);
            f[rot] = id;
        }
        id++;
    }
    return id;
}
