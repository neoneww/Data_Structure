class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> temp;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i] != "../" && logs[i] != "./")
            {
                temp.push_back(logs[i]);
            }
            else if(logs[i] == "../" && temp.size() != 0)
            {
                temp.pop_back();
            }
        }
        return temp.size();
    }
};



/*
"../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).
*/
