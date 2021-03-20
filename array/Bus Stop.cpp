int solve(vector<int>& nums)
{
    vector<pair<pair<int,int>,bool>> temp;

    for(int i=0;i<nums.size();i++)
    {
        temp.push_back({{i,nums[i]},false});
    }   

    sort(temp.begin(),temp.end());
    int prev;
    int cnt = 0;
    for(int i=0;i<temp.size();i++)
    {
        prev = -1;
        if(temp[i].second == false)
        {
            prev = temp[i].first.second; //this will hold the time the ust must arrive
        }

        for(int j=i+1;j<temp.size();j++)
        {
            if(temp[j].second == false && prev < temp[j].first.second)
            {
                prev = temp[j].first.second;
                temp[j].second = true;
            }
        }
        if(prev != -1)
        {
            cnt++;
        }
    }

    return cnt;

}
