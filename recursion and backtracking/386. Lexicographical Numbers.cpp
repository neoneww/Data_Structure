class Solution {
public:
    
    void dfs(int i,int n,vector<int> &ans)
    {
        if(i>n)
            return;
        ans.push_back(i);
        for(int j=0;j<10;j++)
        {
            dfs(10*i+j,n,ans);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            dfs(i,n,ans);
        }
        
        return ans;
    }
};
