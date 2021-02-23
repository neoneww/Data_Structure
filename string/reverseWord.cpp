string solve(string sentence) {
    vector<string> ans;
    string  pp;
    for(int i=0;i<sentence.length();i++)
    {
        if(sentence[i] == ' ')
        {
            ans.push_back(pp);
            pp.clear();
            pp += ' ';
            ans.push_back(pp);
            pp.clear();
        }
        else
        {
            pp += sentence[i];
        }
    }
    ans.push_back(pp);
    pp.clear();
    for(int i=ans.size()-1;i>=0;i--)
    {
        pp+=ans[i];
    }
    return pp;
}
