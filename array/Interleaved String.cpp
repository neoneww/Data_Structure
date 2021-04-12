string solve(string s0, string s1) {
    int i=0,j=0;
    string ans;
    while(i<s0.length()||j<s1.length())
    {
        if(i<s0.length() && j < s1.length())
        {
            ans+=s0[i];
            ans+=s1[j];
            i++;
            j++;
        }else if(i < s0.length())
        {
            ans+=s0[i];
            i++;
        }
        else if(j < s1.length())
        {
            ans+=s1[j];
            j++;
        }
    }

    return ans;
}
