
int lis(vector<int> &arr)
{
    vector<int> ans(arr.size(),1);  //ans array stores the best possible ans till that particular array value
    for(int i=1;i<arr.size();i++)
    {
        for(int j =i-1;j>=0;j--)
        {
            if(arr[j] < arr[i])
            {
                int possibleAns = ans[j]+1;
                if(possibleAns > ans[i])
                {
                    ans[i] = possibleAns;
                }
            }
        }
    }
    int finalResult = 0;
    for(int i=0;i<arr.size();i++)
    {
        finalResult = max(ans[i],finalResult);
    }

    return finalResult;
}



int solve(vector<int>& nums) {
    int ans = lis(nums);
    return ans;   
}
