bool solve(int n, vector<vector<int>>& friends) {
    int allcovered[n];
    for(int i=0;i<n;i++)
    {
        allcovered[i] = 0;
    }
    for(int i=0;i<friends.size();i++)
    {
        for(int j=0;j<friends[i].size();j++)
        {
            allcovered[friends[i][j]] = 1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(allcovered[i] == 0)
        {
            return false;
        }
    }
    return true;
}

//0 to n-1 vector size
