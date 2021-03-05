class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int low =0,high= 0;
	    
	    while(high < n)
	    {
	        if(arr[high] != 0)
	        {
	            swap(arr[low],arr[high]);
	            low++;
	            high++;
	        }
	        else
	        {
	            high++;
	        }
	    }
	}
};
