int solve(vector<int>& nums)
{
    if(nums.size() == 0)
    {
        return 0;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] == 0)
        {
            nums[i] = -1;
        }
    }
    int ans = 0; 
    //basically we need to find the max subarray with sum = 0
    //we try to build a prefix array
    
    vector<int> pre(nums.size());
    pre[0] = nums[0];
    for(int i=1;i<nums.size();i++)
    {
        pre[i] = pre[i-1] + nums[i];
    }
    map<int,int> pp;
    for(int i=0;i<pre.size();i++)
    {
        if(pre[i] == 0)
        {
            ans = max(ans,i+1);
        }
        else if(pp.find(pre[i]) != pp.end())
        {
            ans = max(ans,i-pp[pre[i]]);
        }
        else
        {
            pp[pre[i]] = i;
        }
    } 

    return nums.size()-ans;
}
