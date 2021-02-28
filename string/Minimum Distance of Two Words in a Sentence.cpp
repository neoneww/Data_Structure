int solve(string text, string word0, string word1)
{
    vector<string> pp;
    stringstream check1(text);
    string intermediate; 

    while(getline(check1, intermediate, ' ')) 
    { 
        pp.push_back(intermediate); 
    } 
    int dis = INT_MAX;
    int a,b;
    bool z=false,x=false;
    for(int i=0;i<pp.size();i++)
    {
        if(pp[i] == word0)
        {
            a = i;
            z=true;
        }
        if(pp[i] == word1)
        {
            b = i;
            x=true;
        }

        if(z&&x)
        {
            cout<<a<<b<<endl;
            dis = min(abs(a-b),dis);
            z=false;
            x=false;
        }
    }

    if(dis == INT_MAX)
    {
        return -1;
    }

    return dis-1;
}
