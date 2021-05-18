
// we have to return all the number from one to n in lexicographical order 

// whenever we are making a call we are assuming that the number will print itself and it's family


class Solution {
public:

    void solution(int curNum,int n,vector<int> &ans)
    {
        if(curNum > n)
        {
            return;
        }

        ans.push_back(curNum);
        for(int i = 0; i <= 9; i++)
        {
            solution(10*curNum + i,n,ans);
        }
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for(int i = 1; i <= 9; i++)
        {
            solution(i,n,ans);
        }
        return ans;
    }
};


