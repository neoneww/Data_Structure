int solve(string s, int k)
{
    map<int,int> pp;
    vector<int> brr;

    for(int i=0;i<s.length();i++)
    {
        pp[s[i]]++;
    }

    for(auto itr : pp)
    {
        brr.push_back(itr.second);
    }

    int ans = pp.size();
    if(pp.size() <= k)
    {
        return 0;
    }
    int fin = abs(k-ans);
    int res = 0;
    sort(brr.begin(),brr.end());
    for(int i=0;i<brr.size();i++)
    {
        res+=brr[i];
        fin--;
        if(fin == 0)
        {
            break;
        }
    }


    return res;
}
