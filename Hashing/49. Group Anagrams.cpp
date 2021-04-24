class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> temp;
        
        for(int i=0;i<strs.size();i++)
        {
            string a = strs[i];
            sort(a.begin(),a.end());
            temp[a].push_back(strs[i]);
        }
        
        for(auto i:temp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
