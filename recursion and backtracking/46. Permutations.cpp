class Solution {
public:
    void permut(vector<vector<int>> &ans,vector<int> &nums,vector<bool> &visited,vector<int> &temp)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            permut(ans,nums,visited,temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        permut(ans,nums,visited,temp);
        return ans;
    }
};
