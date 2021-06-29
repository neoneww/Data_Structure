/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    void find(TreeNode *root,TreeNode *target,TreeNode *&ans){
        if(root == NULL) return;
        if(root->val == target->val)
        {
            ans = root;
            return;
        }
        find(root->left,target,ans);
        find(root->right,target,ans);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *ans;
        find(cloned,target,ans);
        return ans;
    }
};
