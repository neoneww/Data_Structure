class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int arr[], int N)
    {
        int low =0,high = 0;
        
        while(high < N)
        {
            if(arr[high] == 0)
            {
                swap(arr[low],arr[high]);
                low++;high++;
            }else{
                high++;
            }
        }
    }
};
