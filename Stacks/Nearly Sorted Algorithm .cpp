#include <iostream>
#include <queue> 
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        priority_queue<int,vector<int>,greater<int>> pp;
        for(int i=0;i<k;i++)
        {
            pp.push(arr[i]);
        }
        int j = 0;
        for(int i=k;i<n;i++)
        {
            int a = pp.top();
            arr[j] = a;
            pp.pop();
            j++;
            pp.push(arr[i]);
        }

        while(pp.empty() == false)
        {
            arr[j] = pp.top();pp.pop();j++;
        }
        for(int i=0;i<=n-1;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
