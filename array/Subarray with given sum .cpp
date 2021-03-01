 vector<int> subarraySum(int arr[], int n, int s){
        int i=0,j=0;
        vector<int> pp;
        int sum = 0;
        sum+=arr[0];
        bool a = true;
        while(j<n)
        {
            if(sum < s)
            {
                j++;
                sum+=arr[j];
            }
            
            if(sum > s)
            {
                sum-=arr[i];
                i++;
            }
            
            if(sum == s)
            {
                pp.push_back(i+1);
                pp.push_back(j+1);
                break;
            }
        }
        if(pp.size() == 0)
        {
            pp.push_back(-1);
            return pp;
        }
        return pp;
        
    }
};
