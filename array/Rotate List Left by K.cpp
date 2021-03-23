vector<int> solve(vector<int>& nums, int k) {
    if(nums.size() == 0 || nums.size() == 1 || k == 0)
    {
        return nums;
    }

    vector<int> temp;
    for(int i=0;i<k;i++)
    {
        temp.push_back(nums[i]);
    }    
    int cnt = 0;

    for(int i = k;i<nums.size();i++)
    {
        nums[i-k] = nums[i];
        cnt++;
    }

    int i = cnt;

    for(int j =0;j<temp.size();j++)
    {
        nums[i] = temp[j];
        i++;
    }

    return nums;


}

//another cool approach
/*
Intuition
EASY AND OPTIMAL

O(n) only without fancy methods of keeping track of cycles etc and absolutely no extra space!

Implementation
Firstly I need the first k elements to become the last k elements right?
what if i just reverse` it?

reverse denoted by -> ( )
[(0 ... k ... n)]
now i have

[(n ....k .....0)]
cool.

but what's the issue ?
the last/(original first) k elements are in reverse order :'(

let's reverse only the after k elements then!

[n ....k(...2,1,0)]
[n.....k(0,1,2...)]
yayyyy
now what?

we do the same reverse with the left half or n:k sublist

[(n.....k)0.....]
[(k.....n)0.....]
WOW it got rotated ❤️ ;)
Time Complexity
\mathcal{O}(n)O(n) since reverse is O(N), and I am not doing anything else

Space Complexity
\mathcal{O}(1)O(1) there is no extra space used in reverse

vector<int> solve(vector<int>& nums, int k) {
    // everyone jumps k steps ahead..
    // thats it.

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());

    return nums;
}
*/
