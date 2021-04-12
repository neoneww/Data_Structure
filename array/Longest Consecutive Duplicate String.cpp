int solve(string s)
{
    if(s.length() == 1 || s.length() == 0)
    {
        return s.length();
    }
    int i=0,j=1;
    int cnt = 1;
    int ans = INT_MIN;
    while(j<s.length())
    {
        if(s[i] == s[j])
        {
            cnt++;
            j++;
        }
        else
        {
            ans = max(ans,cnt);
            cnt = 1;
            i = j;
            j+=1;
        }
    }
  //  cout<<cnt<<"\n";
        ans = max(ans,cnt);
    

    return ans;
}
