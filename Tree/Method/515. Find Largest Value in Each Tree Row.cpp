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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        int pp = INT_MIN;
        while(pendingNode.empty() == false)
        {
            int cnt = pendingNode.size();
            pp = INT_MIN;
            while(cnt--)
            {
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                pp = max(pp,front->val);
                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                }
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                }
            }

            
                ans.push_back(pp);
            
        }
        
        return ans;
    }
};
