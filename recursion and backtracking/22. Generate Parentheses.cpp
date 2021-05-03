class Solution {
public:
    void generate(int open,int close,string str,vector<string> &ans)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(str);
            return;
        }
        
        if(open > close)
        {
            return;
        }

        if(open != 0)
        {
            string temp = str;
            temp.push_back('(');
            generate(open-1,close,temp,ans);
        }

        if(close > 0)
        {
            string temp = str;
            temp.push_back(')');
            generate(open,close-1,temp,ans);
        }

        return;
    }
    
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n;
        int close = n;
        string str = "";
        generate(open,close,str,ans);
        return ans;
    }
};


//whenever we got more number of closing baracket we can make the closing bracket choice 
//whenever we got closing less opening we can't move further 
//when ever closing == opening == 0 we get out ans 
