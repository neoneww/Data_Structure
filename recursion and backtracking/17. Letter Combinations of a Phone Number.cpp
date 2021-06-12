class Solution {
    vector<string> ans;
    unordered_map<char, string> temp;

    void makeCombination(int start, string digits, string currentString) {
        if (start == digits.length()) ans.push_back(currentString);

        for (int i = 0; i < temp[digits[start]].length(); i++) {
            currentString += temp[digits[start]][i];
            makeCombination(start + 1, digits, currentString);
            currentString.pop_back();
        }
    }

    public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return ans;
        temp['2'] = "abc";
        temp['3'] = "def";
        temp['4'] = "ghi";
        temp['5'] = "jkl";
        temp['6'] = "mno";
        temp['7'] = "pqrs";
        temp['8'] = "tuv";
        temp['9'] = "wxyz";
        makeCombination(0, digits, "");
        return ans;
    }
};
