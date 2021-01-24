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
//node are good if path from root to that node is not contained with a node of value greater of that current node
class Solution {
public:
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        dfs(root,INT_MIN);
        return cnt;
    }

    void dfs(TreeNode *root,int max)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->val >= max)
        {
            cnt +=1;
            max = root->val;
        }
        dfs(root->left,max);
        dfs(root->right,max);
    }
};
