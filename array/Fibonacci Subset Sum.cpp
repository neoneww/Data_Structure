void fibNum(vector<int> &nums, int k) {
    int i = 3;
    while (true) {
        int next = nums[i-1] + nums[i - 2];
        if (next > k) return;
        nums.push_back(next);
        i++;
    }
}
int solve(int n) {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    fibNum(nums, n);
    int i = nums.size() - 1;
    // for(int i=0;i<nums.size();i++)
    // {
    //     cout<<nums[i]<<"\n";
    // }
    int cnt = 0;
    while (n > 0) {
        cnt += (n / nums[i]);
        n = (n % nums[i]);
        i--;
    }

    return cnt;
}
