int solve(vector<int>& weights, int limit) {
    sort(weights.begin(), weights.end());
    int i = 0, j = weights.size() - 1;
    int cnt = 0;
    //basically we are doing either take both or take heavier one 
    while(i<=j)
    {
        if(weights[i]+weights[j] <= limit)
        {
            cnt++;
            i++;j--;
        }
        else
        {
            cnt++;
            j--;
        }
    }
    return cnt;
}
