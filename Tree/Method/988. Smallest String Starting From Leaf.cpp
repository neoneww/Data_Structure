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
    
    void formSting(TreeNode *root,vector<string> &all,string s)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) 
        {
            s+= char(root->val+97);
            reverse(s.begin(),s.end());
            all.push_back(s);
            return;
        }
        s+= char(root->val+97);
        formSting(root->left,all,s);
        formSting(root->right,all,s);
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL) return "";
        vector<string> all;
        formSting(root,all,"");
        sort(all.begin(),all.end());
        return all[0];
    }
};
