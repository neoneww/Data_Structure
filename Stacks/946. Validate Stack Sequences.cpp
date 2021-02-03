class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int j = 0;
        stack<int> pp;

        for(int i=0;i<pushed.size();i++)
        {
            pp.push(pushed[i]);
            if(pp.top() == popped[j])
            {
                    while(pp.top() == popped[j])
                    {
                        pp.pop();
                        j++;
                        if(pp.empty())
                        {
                            break;
                        }
                    }
                
            }
        }
        
        return pp.empty();
    }
};


// we are give sequence of push and pop we have to determine whetr the stack is full or empty 
// we will push int from the push vector and we will keep a pointer at the initial top of the our array and keep checking it 
