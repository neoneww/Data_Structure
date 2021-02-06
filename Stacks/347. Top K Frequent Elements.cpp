class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int,int> qq;
        for(int i=0;i<nums.size();i++)
        {
            qq[nums[i]]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pp;
        // for (auto it = mymap.begin(); 
        //  it != mymap.end(); ++it) 
        // cout << it->first << " = "
        //      << it->second << '\n'; 

        for (auto it = qq.begin(); it != qq.end(); ++it) 
        {
            pair<int,int> a;
            a = make_pair(it->second,it->first);
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

        return ans;
        
    }
};

//we to return k most frequent number 
// make a map and calculate the frequency of each number 
// then we can use the min heap
