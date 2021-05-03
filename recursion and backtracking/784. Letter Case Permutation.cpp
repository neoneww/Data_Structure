class Solution {
public:

    void generate(int curr,string str,set<string> &ans)
    {
        if(curr == str.length())
        {
            ans.insert(str);
            return;
        }

        if(str[curr] - 'a' >= 0 && str[curr]-'a' <= 25 || str[curr] - 'A' >= 0 || str[curr] - 'A' <= 25)
        {
            string temp1 = str;
            string temp2 = str;
            temp1[curr] = toupper(temp1[curr]);
            temp2[curr] = tolower(temp2[curr]);
            generate(curr+1,temp1,ans);
            generate(curr+1,temp2,ans);
        }

        generate(curr+1,str,ans);
    }

    vector<string> letterCasePermutation(string S)
    {
        int curr = 0;
        set<string> ans;
        generate(curr,S,ans);
        vector<string> finAns;
        for(auto i:ans)
        {
            finAns.push_back(i);
        }
        return finAns;
    }
};

//first we will check wheter it is a  letter or not
