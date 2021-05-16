class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.length() <= 1)
        {
            return s.length();
        }
        
        
        int ans = 0;
        unordered_map<char,int> temp;
        int i = 0,j = 1;
        temp[s[i]]++;temp[s[j]]++;
        
        while(j < s.length())
        {
            ans = max(j-i,ans);
            
            if(temp[s[j]] == 2)
            {
                while(temp[s[j]] == 2)
                {
                    temp[s[i]]--;
                    i++;
                }
            }
            else
            {
                j++;
                temp[s[j]]++;
            }
        }
        
        ans = max(j-i,ans);
        
        return ans;
    }
};
