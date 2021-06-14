class Solution {
public:
     void makeChoice(int i,set<vector<int>> &ans,vector<int> &nums,vector<int> &temp)
    {
        if(i == nums.size())
        {
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        makeChoice(i+1,ans,nums,temp);
        temp.pop_back();
        makeChoice(i+1,ans,nums,temp);
    }
    
        
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> finAns;
        set<vector<int>> ans;
        vector<int> temp;
        makeChoice(0,ans,nums,temp);
        for(auto i:ans)
        {
            finAns.push_back(i);
        }
        
        return finAns;
    }
};
