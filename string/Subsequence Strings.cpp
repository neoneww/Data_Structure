bool solve(string s1, string s2) {
    if(s1 == s2  || s1.length() == 0 && s2.length() != 0 )
    {
        return true;
    }
    if(s1.length() > s2.length() || s1.length() != 0 && s2.length() == 0)
    {
        return false;
    }

    int i=0,j=0;
    while(i<s1.length() && j<s2.length())
    {
        if(s1[i] == s2[j])
        {
            i++;j++;
        }
        else
        {
            j++;
        }
    }

    if(i < s1.length())
    {
        return false;
    }

    return true;
}
