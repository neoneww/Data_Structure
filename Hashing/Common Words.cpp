int solve(string s0, string s1)
{
    if(s0.length() ==0 && s1.length() == 0 ||s0.length() !=0 && s1.length() == 0 ||s0.length() ==0 && s1.length() != 0  )
    {
        return 0;
    }
    string a;
    unordered_map<string,int> pp; //string and no of it's occurence 
    for(int i=0;i<s0.length();i++)
    {
        if(s0[i] == ' ')
        {
            pp[a]++;
            a.clear();
        }
        else
        {
            s0[i] = tolower(s0[i]);
            a+=s0[i];
        }
    }
    pp[a]++;
    a.clear();
    int ans = 0;

    for(int i=0;i<s1.length();i++)
    {
        if(s1[i] == ' ')
        {
            if(pp.find(a) != pp.end() && pp[a] != 0)
            {
                
                ans++;
                pp[a] = 0;
            }
            a.clear();
        }
        else
        {
            s1[i] = tolower(s1[i]);

            a+=s1[i];
        }
    }
    if(pp.find(a) != pp.end() && pp[a] != 0)
    {
        ans++;
    }

    return ans;    
}
