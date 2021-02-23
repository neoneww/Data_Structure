bool solve(string s0, string s1) {
    if(s0.length() == s1.length() && s0 != s1 || s0.length() != s1.length()+1)
    {
        return false;
    }
    int cnt = 0;
    int i = 0,j = 0;
    while(i<s0.length())
    {
        if(cnt == 2)
        {
            return false;
        }
        if(s0[i] != s1[j])
        {
            cnt++;
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if(cnt > 1)
    {
        return false;
    }
    return  true;
}
