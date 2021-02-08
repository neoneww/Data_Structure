int solve(vector<int>& prices)
{
    int n = prices.size()-1;

    stack<int> pp;  
    int ans = 0;

    for(int i=n;i>=0;i--)
    {
        if(pp.empty() == true)
        {
            pp.push(prices[i]);
        }
        else
        {
            while(pp.empty() == false && prices[i] >  pp.top())
            {
             
                pp.pop();
            }

             if(pp.empty() == true)
            {
                pp.push(prices[i]);
            }
            else
            {
                ans = max(ans,abs(pp.top()-prices[i]));
            }

        }
    }

    return ans;
    
}
