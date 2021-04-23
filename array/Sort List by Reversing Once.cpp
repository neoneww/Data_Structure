bool solve(vector<int>& nums) {
    if(nums.size() == 1|| nums.size() == 0)
    {
        return true;
    }
    vector<int> temp;
    for(int i=0;i<nums.size();i++)
    {
        temp.push_back(nums[i]);
    }

    sort(temp.begin(),temp.end());
    int i,j;
    bool aa = false;
    for(i=0;i<nums.size();i++)
    {
        if(nums[i] != temp[i])
        {
            aa = true;
            break;
        }
    }

    // we got ith position;

    for(j=nums.size()-1;j>=0;j--)
    {
        if(nums[j] != temp[j])
        {
            aa = true;
            break;
        }
    }

    if(aa == false)
    {
        return true;
    }

     do
    {
        i++;
        if (nums[i - 1] < nums[i])
            return false;
    } while (i != j);

    return true;
}
