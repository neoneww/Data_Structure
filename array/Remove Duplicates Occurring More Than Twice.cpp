vector<int> solve(vector<int>& nums)
{
    int k=nums.size()-1;
    int i=0,j=0;
    int siz = nums.size();

    while(i<siz)
    {
        int cnt = 0;
        
        while(nums[i] == nums[j] && j < siz)
        {
            if(cnt <= 1)
            {
                nums.push_back(nums[j]);
            }
            cnt++;
            j++;
        }

        i = j;
    }    
    while(siz--)
    {
        nums.erase(nums.begin());
    }
    return nums;
}

/*
    we have to remove all those element which occur more than twice so my plan is to first
    include element untill and unless their cnt <= 2
*/
