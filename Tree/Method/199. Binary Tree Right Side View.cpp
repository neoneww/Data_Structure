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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        ans.push_back(root->val);
        while(pendingNode.empty() != true)
        {
            int cnt = pendingNode.size();
            while(cnt--)
            {
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                }
                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                }
            }
            if(pendingNode.empty() != true)
            {
                TreeNode *front = pendingNode.front();
                ans.push_back(front->val);
            }
        }

        return ans;
    }
};
