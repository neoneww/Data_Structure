class Solution {
public:
    string frequencySort(string s)
    {
        map<char,int> pp;

        for(int i=0;i<s.length();i++)
        {
            pp[s[i]]++;  // we are just storing the frequency of each char 
        }    

        //now we will make a heap of pairs 

        priority_queue<pair<int,int>> qq;

        //traverse the map and store the char and frequency into a heap
        for(auto i : pp)
        {
            pair<int,char> a;

            a = make_pair(i.second,i.first);

            qq.push(a);
        }
        string ans;
        while(qq.empty() == false)
        {
            pair<int,char> a;
            a = qq.top();
            qq.pop();
            while(a.first--)
            {
                ans+=a.second;
            }
        }

        return ans;
    }
};
