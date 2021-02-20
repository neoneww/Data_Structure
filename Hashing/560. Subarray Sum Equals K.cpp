class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pp; //we will store the freq instead of the index 
        int cnt = 0; int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
            if(ans == k)
            {
                cnt++;
            }
            if(pp.find(ans-k) != pp.end())
            {
                cnt+=pp[ans-k];
            }

            pp[ans]++;
        }

        return cnt;
    }
};
