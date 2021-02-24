class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int> pp;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(pp.find(nums[i]) != pp.end())
            {
                cnt += pp[nums[i]];
                pp[nums[i]]++;
            }
            else
            {
                pp[nums[i]]++;
            }
        }
        
        return cnt;
    }
};
