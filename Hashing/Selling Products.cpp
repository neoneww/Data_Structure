int solve(vector<int>& items, int n) {
    unordered_map<int,int> pp;
    vector<int> ans;
    for(int i=0;i<items.size();i++)
    {
        pp[items[i]]++;
    }
    for(auto itr : pp)
    {
        ans.push_back(itr.second);
    }
    int j = 0;
    sort(ans.begin(),ans.end());
    while(n > 0)
    {
        n-=ans[j];
        if(n < 0)
        {
            break;
        }
        j++;
    }

    return pp.size()-j;
}
