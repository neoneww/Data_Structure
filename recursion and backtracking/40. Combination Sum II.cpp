class Solution {
    public:
    void combination(int i, vector<int> &normal, vector<int> &currArray, set<vector<int>> &ans,
                     int sum, int target) {
        if (sum == target) {
            // sort(currArray.begin(),currArray.end());
            ans.insert(currArray);
        }

        if (i == normal.size() || sum > target) return;

        sum += normal[i];
        currArray.push_back(normal[i]);
        combination(i + 1, normal, currArray, ans, sum, target);
        sum -= normal[i];
        currArray.pop_back();
        combination(i + 1, normal, currArray, ans, sum, target);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());

        set<vector<int>> ans;
        vector<int> temp;
        combination(0, candidates, temp, ans, 0, target);
        vector<vector<int>> finAns;
        for (auto i : ans) {
            finAns.push_back(i);
        }
        return finAns;
    }
};
