int solve(vector<int>& nums, vector<int>& mult)
{
    sort(nums.begin(),nums.end());
    sort(mult.begin(),mult.end());


    int i=0,j=nums.size()-1,k=0,l=mult.size()-1;
    int ans=0;
    while(i<=j&&k<=l)
    {
        if(nums[i]*mult[k] >= nums[j]*mult[l])
        {
            //cout<<mult[k]<<"\n";
            ans+=(nums[i]*mult[k]);
            i++;k++;
        }
        else if(nums[i]*mult[k] < nums[j]*mult[l])
        {
            ans+=(nums[j]*mult[l]);
            j--;l--;
        }
    }

    return ans;
    
}



// we need to take 4 variable then compare from the front and pair from the back 
