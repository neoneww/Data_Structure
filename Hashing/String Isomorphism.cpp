bool solve(string s, string t)
{
    unordered_map<char,char> pp; // this will store mapping from word one to word two
    unordered_map<char,char> qq; //this will store mapping from word two to word one

    for(int i=0;i<s.length();i++)
    {
        if(pp.find(s[i]) != pp.end() && pp[s[i]] != t[i] || qq.find(t[i]) != qq.end() && qq[t[i]] != s[i])
        {
            return false;
        }

        pp[s[i]] = t[i];
        qq[t[i]] = s[i];
    }

    return true;      
}
