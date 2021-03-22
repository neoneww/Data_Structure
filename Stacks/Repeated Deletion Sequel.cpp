string solve(string s,int k)    // we have a string s and we have to delete k consecutive string 
{
    if(k == 1 || s.length() == 1)
    {
        return "";
    }
    stack<pair<char,int>> freq;
    
    for(int i=0;i<s.length();i++)
    {
        if(freq.empty())
        {
            freq.push({s[i],1});
        }
        else
        {
            if((freq.top()).first == s[i])
            {
                (freq.top()).second++;

                if((freq.top()).second == k)
                {
                    freq.pop();
                }
            }
            else
            {
                freq.push({s[i],1});
            }
        }
    }
    string ans;
    while(freq.empty() == false)
    {
        string append = string((freq.top()).second,
                                   (freq.top()).first);
            freq.pop();
            ans = append + ans;
    }

    

    return ans;
}
