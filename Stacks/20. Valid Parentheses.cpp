class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        int i = 0;
        while(i<s.length())
        {
            if(temp.empty() == false && temp.top() == '(' && s[i] == ')' ||temp.empty() == false && temp.top() == '[' && s[i] == ']' || temp.empty() == false && temp.top() == '{' && s[i] == '}' )
            {
                temp.pop();
            }else if(temp.empty() == false && s[i] == ')' || temp.empty() == false && s[i] == '}' || temp.empty() == false && s[i] == ']')
            {
                return false;
            }
            else{
                temp.push(s[i]);
            }
            i++;
        }
        
        if(temp.size() != 0)
        {
            return false;
        }
        
        return true;
    }
};
