/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void convert(TreeNode *root,string s,vector<string> &ans)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val);
        convert(root->left,s,ans);
        convert(root->right,s,ans);
    }
    
    int sumNumbers(TreeNode* root)
    {
        vector<string> ans;
        convert(root,"",ans);
        int temp = 0;
        for(int i=0;i<ans.size();i++)
        {
            temp += stoi(ans[i]);
        }
        return temp;
    }
};
