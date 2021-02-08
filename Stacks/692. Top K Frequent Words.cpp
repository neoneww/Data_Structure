class Solution {

static bool cmp(pair<string, int>& a, 
         pair<string, int>& b) 
{ 
        if (a.second == b.second)
                return a.first.compare(b.first) < 0;    
    return a.second > b.second; 
}

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
     
        map<string, int>freq;
        
        //created frequency map
        for(string s:words)
        {
            freq[s]++;
        }
        
        //sort the map based on value
         vector<pair<string, int> > A; 
  
    // Copy key-value pair from Map 
    // to vector of pairs 
    for (auto& it : freq) { 
        A.push_back(it); 
    } 
  
    // Sort using comparator function 
    sort(A.begin(), A.end(), cmp); 
    
     
          vector<string>ans;
        //put first k words in final vector
        for(int i=0;i<k;i++)
        {
            ans.push_back(A[i].first);
        }
        return ans;
        
    }
};
