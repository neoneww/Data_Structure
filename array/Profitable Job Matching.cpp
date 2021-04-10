int solve(vector<int>& people, vector<int>& jobs, vector<int>& profits)
{
    vector<pair<int,int>> temp;

    for(int i=0;i<jobs.size();i++)
    {
        temp.push_back({profits[i],jobs[i]});
    }
    
    int ans=0;
    sort(temp.begin(),temp.end(),greater<pair<int,int>>());
    sort(people.begin(),people.end());

    for(int i=0;i<people.size();i++)
    {
        for(int j=0;j<temp.size();j++)
        {
           // cout<<temp[j].second<<"\n";
            if(people[i] >= temp[j].second)
            {
                ans+=temp[j].first;
                //cout<<ans<<"\n";
                break;
            }
        }
    }

    return ans;
       
}



/*

make a pair of jobs and profit then sort them according to the profint and also sort the people strength 
o(n^2) algo is coming
*/



//i people will have people[i] strength;
//j job will req job[j] strength profit[j] amt of profit 


//dumb me updates are like each person can do a certain job morethan 1 time 
