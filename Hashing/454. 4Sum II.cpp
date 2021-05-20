/*
    1) 

    we can't make a big array  why = cause if we did so we will need to sort it and it will be pretty difficult
    to get all the number from different array and and in an increasing oder


    
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int,int> temp;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                temp[nums1[i]+nums2[j]]++;   //making all the  pair of 2 vectors 
            }
        }
        int cnt = 0;
        for(int i = 0; i < nums3.size(); i++)
        {
            for(int j = 0; j < nums4.size(); j++)
            {
                if(temp.find(0-(nums3[i]+nums4[j])) != temp.end())
                {
                    cnt+=temp[0-(nums3[i]+nums4[j])];
                }
            }
        }

        return cnt;
    }
};
