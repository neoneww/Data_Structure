string solve(string s)
{
    stack<char> pp;
    int i = 0;
    while(i < s.length())
    {
        if(s[i] == '<' && i+1 < s.length() && s[i+1] == '-')
        {
            i+=2;
            if(pp.empty() == false)
            {
                pp.pop();
            }
        }
        else
        {
            pp.push(s[i]);
            i++;
        }
    }
    string ans;
    while(pp.empty() == false)
    {
        char c;
        c = pp.top();
        pp.pop();
        ans+=c;
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

//we  have a string where we have  "<-" -> this works as a backspace and we have 
