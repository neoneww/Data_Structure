class Solution {
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char,int> temp;
        for(int i=0;i<s.length();i++)
        {
            temp[s[i]]++;
        }

        for(int i=0;i<t.length();i++)
        {
            if(temp.find(t[i]) == temp.end())
            {
                return t[i];
            }else
            {
                if(temp[t[i]] == 0)
                {
                    return t[i];
                }

                temp[t[i]]--;
            }
        }

        return t[t.length()-1];
    }
};
