bool solve(vector<int>& nums)
{
    if(nums.size() == 1)
    {
        return true;
    }
    int idx = 0; //this will store the idx of position where we will have nums[i] == 1

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] == 1)
        {
            idx = i;
            break;
        }
    }
    // we wil deal with the excepions later 

    if(idx == 0)
    {
        if(nums[idx+1] == 2)
        {
            int cnt = 1;
            for(int i=idx;i<nums.size();i++)
            {
                if(nums[i] != cnt)
                {
                    return false;
                }

                cnt++;
            }
            return true;
        }
        else if(nums[idx+1] == nums.size())
        {
            int cnt = nums.size();
            for(int i=idx+1;i<nums.size();i++)
            {
                if(nums[i] != cnt)
                {
                    return false;
                }
                cnt--;
            }
             return true;
        }
        else
        {
            return false;
        }
    }
    else if(idx == nums.size()-1)
    {
        if(nums[idx-1] == 2)
        {
            int cnt = 1;
            for(int i=idx;i>=0;i--)
            {
                if(nums[i] != cnt)
                {
                    return false;
                }
                cnt++;
            }
             return true;
        }
        else if(nums[idx-1] == nums.size())
        {
            int cnt = nums.size();
            for(int i=idx-1;i>=0;i--)
            {
                if(nums[i] != cnt)
                {
                    return false;
                }
                cnt--;
            }
             return true;
        }
        else
        {
            return false;
        }
    }

    if(nums[idx-1] == 2)
    {
        int cnt = 1;
        for(int i=idx;i>=0;i--)
        {
            if(nums[i] != cnt)
            {
                return false;
            }
            cnt++;
        }

        cnt = nums.size();

        for(int i=idx+1;i<nums.size();i++)
        {
            if(nums[i] != cnt)
            {
                return false;
            }
            cnt--;
        }
    }else if(nums[idx-1] == nums.size())
    {
        int cnt = 1;
        for(int i=idx;i<nums.size();i++)
        {
            if(nums[i] != cnt)
            {
                return false;
            }
            cnt++;
        }
        cnt = nums.size();
        for(int i=idx-1;i>=0;i--)
        {
            if(nums[i] != cnt)
            {
                return false;
            }
            cnt--;
        }
    }else {
        return false;
    }
    return true;
}





//my thought process is to find the index of position of the place where is num 1 then i can 
//look backward or foreward for a increasing range 
//basically we will look in foreward direction and if we found the increasing number we will /////also look in backward direction 
