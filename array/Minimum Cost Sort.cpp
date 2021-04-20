int solve(vector<int>& nums) {
    vector<int> temp1,temp2;
    for(int i=0;i<nums.size();i++)
    {
        temp1.push_back(nums[i]);
        temp2.push_back(nums[i]);
    }
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end(),greater<int>());
    int ans1=0,ans2=0;

    for(int i=0;i<nums.size();i++)
    {
        ans1+=(abs(nums[i]-temp1[i]));
        ans2+=(abs(nums[i]-temp2[i]));
    }

    return min(ans1,ans2);
}
