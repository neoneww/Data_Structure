#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        unordered_set<int> pp;
        for(int i=0;i<n;i++)
        {
            int a = 0;
            cin>>a;
            pp.insert(a);
        }
        unordered_set<int>::iterator itr = pp.begin();
        bool aw = false;
        while(itr != pp.end())
        {
            int a = (*itr)+m;
            int b = (*itr)-m;
            //cout<<(*itr)<<" "<<a<<"\n";
            if(pp.find(a) != pp.end())
            {
                cout<<1<<"\n";
                aw= true;
                break;
            }
            
            if(pp.find(b) != pp.end())
            {
                cout<<1<<"\n";
                aw = true;
                break;
            }
            itr++;
        }
        if(aw == false)
        {
            cout<<-1<<"\n";
        }
    }
}
