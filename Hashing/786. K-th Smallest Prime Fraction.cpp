/*
    this question seems like a pq question i mean just run the loops two time get all the fractions and 
    then put them in a max pq and get the kth smallest pq 
*/
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        priority_queue<pair<float,pair<int,int>>> temp;
        for(int i = 0; i<arr.size()-1; i++)
        {
            for(int j = i+1; j<arr.size(); j++)
            {
                // float a = (float)arr[i]/arr[j];
                // cout<<a<<"\n";
                temp.push(make_pair((float)arr[i]/arr[j],make_pair(arr[i],arr[j])));
            }
        }

        while(temp.size() != k)
        {
            temp.pop();
        }

        vector<int> ans;

        pair<float,pair<int,int>> qq; 

        qq = temp.top();

        ans.push_back(qq.second.first);
        ans.push_back(qq.second.second);

        return ans;      
    }
};
