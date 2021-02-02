class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> pp;
        for(int i=0;i<s.length();i++)
        {
            if(pp.empty() == false && s[i] == ')' && pp.top() == '(')
            {
                pp.pop();
            }
            else
            {
                pp.push(s[i]);
            }
        }

        return pp.size();
    }
};


/// just remove all the valid brackets from the string and get the answer 
