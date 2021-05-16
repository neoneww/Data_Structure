//o(n^2) solution pq timecomplexity == logn for heap

vector<int> solve(vector<int>& nums, int k)
{
    vector<int> ans;
    priority_queue<int> temp;
    if(nums.size() <=  1)
    {
        return nums;
    }  

    for(int i=0;i<nums.size()-1;i++)
    {
        int sum = nums[i];
        temp.push(sum);
        for(int j=i+1;j<nums.size();j++)
        {
            sum += nums[j];
            temp.push(sum);
        }
    }
    temp.push(nums[nums.size()-1]);
    while(k--)
    {
        ans.push_back(temp.top());
        temp.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
