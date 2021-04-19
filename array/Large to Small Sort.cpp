vector<int> solve(vector<int>& nums)
{
    priority_queue<int> temp1;
    priority_queue<int,vector<int>,greater<int>> temp2;
    for(int i=0;i<nums.size();i++)
    {
        temp1.push(nums[i]);
        temp2.push(nums[i]);
    }
    vector<int> ans;
    int n = nums.size();

    while(ans.size() != n)
    {
        int a = temp1.top();
        temp1.pop();
        ans.push_back(a);
        if(ans.size() == n)
        {
            break;
        }
        a = temp2.top();
        temp2.pop();
        ans.push_back(a);
    }    

    return ans;
}



// we will just make 1 max heap and 1 min heap
