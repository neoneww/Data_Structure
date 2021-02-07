class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int,vector<int>,greater<int>> pp;
        for(int i=0;i<nums.size();i++)
        {
            pp.push(nums[i]);
        }

        while(pp.size() > k)
        {
            pp.pop();
        }

        int ans = pp.top();

        return ans;
        
    }
};
