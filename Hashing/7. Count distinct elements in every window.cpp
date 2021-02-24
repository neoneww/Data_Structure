vector <int> countDistinct (int arr[], int n, int k)
{
    vector<int> ans;
    unordered_map<int,int> pp;
    
    if(n<=k)
    {
        for(int i=0;i<n;i++)
        {
            pp[arr[i]]++;
        }
        
        ans.push_back(pp.size());
    }else
    {
        for(int i=0;i<k;i++)
        {
            pp[arr[i]]++;
        }
        ans.push_back(pp.size());
        for(int i=k;i<n;i++)
        {
            pp[arr[i]]++;
            pp[arr[i-k]]--;
            if(pp[arr[i-k]] == 0)
            {
                pp.erase(arr[i-k]);
            }
            int cnt = pp.size();
            ans.push_back(cnt);
        }
    }
    
    return ans;
}
