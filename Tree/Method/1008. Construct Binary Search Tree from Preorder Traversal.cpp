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
    TreeNode* solve(vector<int> &preorder,int &idx,int lr,int hr){
        if(idx >= preorder.size() || preorder[idx] < lr || preorder[idx] > hr){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[idx]);
        idx++;
        root->left = solve(preorder,idx,lr,root->val);
        root->right = solve(preorder,idx,root->val,hr);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder,i,-1e9,1e9);
    }
};
