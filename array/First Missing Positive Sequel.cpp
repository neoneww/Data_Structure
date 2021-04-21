int solve(vector<int>& arr)
{
    int temp = 1;
    if(arr[0] == 0)
    {
        temp = 0;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] != temp)
        {
            return temp;
        }

        temp++;
    }    

    return temp;
}
