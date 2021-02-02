int solve(string s) {
    int cnt = 0;
    stack<char> pp;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ')' && pp.empty() == false && pp.top() == '(')
        {
            cnt+=2;
            pp.pop();
        }
        else{
            pp.push(s[i]);
        }
    }
    return cnt;
}
// we have to store longest balanced subsequence 

//
