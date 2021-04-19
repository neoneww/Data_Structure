int solve(vector<string>& shows, vector<int>& durations, int k)
{
    unordered_map<string,int> temp;
    vector<int> ans;
    for(int i=0;i<shows.size();i++)
    {
        temp[shows[i]]+=durations[i];
    } 
    for(auto i:temp)
    {
        ans.push_back(i.second);
    }
    int cnt = 0;
    sort(ans.begin(),ans.end());
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(k==0)
            break;

        cnt+=ans[i];
        k--;
    }

    return cnt;
}
