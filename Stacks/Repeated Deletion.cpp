string solve(string s) {
    int a = 0;
    stack<char> pp;
    string ans;
    int i = 0;
    while(i < s.length())
    {
        if(pp.empty() == false && pp.top() == s[i])
        {
            while(s[i] == pp.top())
            {
                i++;
            }
            pp.pop();
        }else{
            pp.push(s[i]);
            i++;
        }
    }

    while(pp.empty() == false)
    {
        char a = pp.top();
        pp.pop();
        ans+=a;
    }

    reverse(ans.begin(),ans.end());

    return ans;
}
