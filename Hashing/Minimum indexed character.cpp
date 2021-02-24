int minIndexChar(string a, string b)
{
    unordered_map<char,int> pp;
    
    for(int i=0;i<a.length();i++)
    {
        if(pp.find(a[i]) == pp.end())
        {
            pp[a[i]] = i;
        }
    }
    
    bool as = false;
    
    int ans = INT_MAX;
    
    for(int i=0;i<b.length();i++)
    {
        if(pp.find(b[i]) != pp.end())
        {
            as = true;
            ans = min(ans,pp[b[i]]);
            //cout << ans << endl;
        }
    }
    if(as == false)
    {
        return -1;
    }
    
    return ans;
    
}
