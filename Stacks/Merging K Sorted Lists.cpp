vector<int> solve(vector<vector<int>>& lists)
{
    //let's make a min pq and add all the 3 initial elements 

   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pp; 
    
    for(int i=0;i<lists.size();i++)
    {
        if(lists[i].size() != 0)
        {
            pp.push(make_pair(lists[i][0],make_pair(i,0)));
        }
    }

    vector<int> ans;

    while(pp.empty() == false)
    {
        pair<int,pair<int,int>> a;

        a = pp.top();
        
        pp.pop();

        ans.push_back(a.first);

        int arrno = a.second.first;
        int arrind = a.second.second; //element number 

        if(arrind < lists[arrno].size()-1)
        {
            arrind++;
            pair<int,pair<int,int>> q;
            q = make_pair(lists[arrno][arrind],make_pair(arrno,arrind));
            pp.push(q);
        }
    }

    return ans;

}
