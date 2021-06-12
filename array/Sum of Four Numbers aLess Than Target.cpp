int binarySearchCount(vector<int> &arr, int n, int key)
{
    int left = 0;
    int right = n - 1;
 
    int count = 0;
 
    while (left <= right) {
        int mid = (right + left) / 2;
 
        // Check if middle element is
        // less than or equal to key
        if (arr[mid] <= key) {
 
            // At least (mid + 1) elements are there
            // whose values are less than
            // or equal to key
            count = mid + 1;
            left = mid + 1;
        }
 
        // If key is smaller, ignore right half
        else
            right = mid - 1;
    }
 
    return count;
}

int solve(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d, int target) {
    int cnt = 0;
    // making a array of all the pairs from first two array
    // this ig gurantees the different identity
    vector<int> temp1;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            temp1.push_back(a[i] + b[j]);  // makign all the possible pairs then check if we have
                                           // another pair less than target
        }
    }
    int q = temp1.size();
    sort(temp1.begin(),temp1.end());

    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < d.size(); j++) {
            int pp = target - (c[i] + d[j]);
            cnt += binarySearchCount(temp1,q,pp);
        }
    }

    return cnt;
}
