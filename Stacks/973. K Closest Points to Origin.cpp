class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<double,vector<int>>> pp;

        for(int i=0;i<points.size();i++)
        {
            int a = points[i][0];
            int b = points[i][1];
            double res1 = (a*a) + (b*b);
            double res = pow(res1,0.5);
            pair<double,vector<int>> aa;
            aa = make_pair(res,points[i]);
            pp.push(aa);
        }

        while(pp.size() > k)
        {
            pp.pop();
        }

        while(pp.empty() == false)
        {
            pair<int,vector<int>> a;
            a = pp.top();
            pp.pop();
            ans.push_back(a.second);
        }

        return ans;

    }
};

// we have to find k closest point to the origin 
// simply make a pair of coordinates and distances then make a max heap of this pair 
// then keep pooping the element 
