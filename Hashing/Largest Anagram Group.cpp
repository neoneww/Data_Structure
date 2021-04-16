int solve(vector<string>& words) {
    unordered_map<string,int> temp;
    for(int i=0;i<words.size();i++)
    {
        sort(words[i].begin(),words[i].end());
    }
    for(int i=0;i<words.size();i++)
    {
        temp[words[i]]++;
    }
    int ans = INT_MIN;
    for(auto i:temp)
    {
        ans = max(ans,i.second);
    }

    return ans;
}
