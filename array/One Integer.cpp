int solve(vector<int>& nums) {
    if(nums.size() <= 1)
    {
        return 0;
    }
    priority_queue<int,vector<int>,greater<int>> temp;
    
    for(int i=0;i<nums.size();i++)
    {
        temp.push(nums[i]);
    }
    int ans = 0;
    while(temp.size() != 1)
    {
        int a = temp.top();
        temp.pop();
        int b = temp.top();
        temp.pop();
        ans+=(a+b);
       // cout<<a<<" "<<b<<" "<<a+b<<" "<<"\n";
        temp.push(a+b);
    }

    return ans;
}
