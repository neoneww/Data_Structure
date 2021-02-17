#include <iostream>
using namespace std;
// this problem has a overlapping sub problem property // we want previous answer to calculate our final ans 
int main()
{
    int n;
    cin>>n;
    int arr[n]; // we have n numbers 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    //do we have a subset which have a sum equal to tar 
    bool dp[n+1][tar+1]; // size and column 

    for (int i=0;i<n+1;i++)
    {
        for(int j=0;j<tar+1;j++)
        {
            dp[i][j] = false;
        }
    }

    for(int i=0;i<n+1;i++)
    {
        dp[i][0] = true;
    }

    for(int j=1;j<tar+1;j++)
    {
        dp[0][j] = false;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<tar+1;j++)
        {
            if(dp[i-1][j] == true)
            {
                dp[i][j] = true;
            }
            else
            {
                int val = arr[i-1];
                if(val <= j)
                {
                    if(dp[i-1][j-val] == true)
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }
    }

    if(dp[n][tar] == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;

}
