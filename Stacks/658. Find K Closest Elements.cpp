class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        priority_queue<pair<int,int>> pp;

        vector<int> ans;
        
        for(int i=0;i<arr.size();i++)
        {
            pair<int,int> a;
            a = make_pair(abs(arr[i]-x),arr[i]);
            pp.push(a);
        }

        while(pp.size() > k)
        {
            pp.pop();
        }

        while(pp.empty() == false)
        {
            pair<int,int> a;
            a = pp.top();
            pp.pop();
            ans.push_back(a.second);
        }
        sort(ans.begin(),ans.end());
        return ans;   
    }
};

// we have to return k closest integer to x 
// we will first a min heap
