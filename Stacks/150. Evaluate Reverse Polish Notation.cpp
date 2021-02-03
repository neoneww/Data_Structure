class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string> pp;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                string a = pp.top();
                pp.pop();
                string b = pp.top();
                pp.pop();
                int res1,res2;
                stringstream my1(a);
                stringstream my2(b);
                my1 >> res1;
                my2 >> res2;
                if(tokens[i] == "+")
                {
                    int result = res1 + res2;
                    ostringstream str1;
                    str1 << result; 
                    string geeek = str1.str();
                    pp.push(geeek);
                }
                if(tokens[i] == "/")
                {
                    int result = res2 / res1;
                    ostringstream str1;
                    str1 << result; 
                    string geeek = str1.str();
                    pp.push(geeek);
                }
                if(tokens[i] == "-")
                {
                    int result = res2 - res1;
                    ostringstream str1;
                    str1 << result; 
                    string geeek = str1.str();
                    pp.push(geeek);
                }
                if(tokens[i] == "*")
                {
                    int result = res2 * res1;
                    ostringstream str1;
                    str1 << result; 
                    string geeek = str1.str();
                    pp.push(geeek);
                }
            }
            else {
                pp.push(tokens[i]);
            }
        }

        string finalans = pp.top();
        pp.pop();
        stringstream my11(finalans);
        int anss;

        my11 >> anss;
        return anss;

    }
};

// we simply just have to evaluate the reverse polish notation but the thing is that we  are given the expression in string
// we will make a stack of string and then we will have to convert the string to number then again back to string and then we will push that again in stack :(
// then final ans again to int 
