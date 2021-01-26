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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> midAns;
        if(root == NULL)
        {
            return ans;
        }
        midAns.push_back(root->val);
        ans.push_back(midAns);
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        while(pendingNode.empty() != true)
        {
            int cnt = pendingNode.size();
            vector<int> pp;
            while(cnt--)
            {
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                    pp.push_back(front->left->val);
                }
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                    pp.push_back(front->right->val);
                }
            }
            if(pp.size() != 0)
            {   
                ans.push_back(pp);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
