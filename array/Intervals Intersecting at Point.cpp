int solve(vector<vector<int>>& intervals, int point) {
    int cnt = 0;
    for(int i=0;i<intervals.size();i++)
    {
        int a = intervals[i][0];
        int b = intervals[i][1];

        if(point >= a && point <= b)
        {
            cnt++;
        }
    }

    return cnt;
}
