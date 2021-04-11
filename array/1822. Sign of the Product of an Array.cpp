class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        int odd=0,zero=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < 0)
            {
                odd++;
            }
            else if(nums[i] == 0)
            {
                zero = 1;
            }
        }

        if(zero ==  1)
        {
            return 0;
        }else if(odd%2 == 0)
        {
            return 1;
        }    
        
        return -1;
    }
};
