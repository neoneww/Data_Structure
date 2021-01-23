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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> pendingNode;
        queue<TreeNode*> lol;
        vector<vector<int>> ans;
        if(root == NULL)
        {
            return ans;
        }
        vector<int> pq;
        pq.push_back(root->val);
        ans.push_back(pq);
        pendingNode.push(root);
        while(pendingNode.empty() != true)
        {
            int cnt = pendingNode.size();
            while(cnt--)
            {
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                    lol.push(front->left);
                }
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                    lol.push(front->right);
                }
            }
            vector<int> arr;
            while(lol.empty() != true)
            {
                TreeNode *wow = lol.front();
                lol.pop();
                arr.push_back(wow->val);
            }
            if(arr.size() != 0)
            {
                ans.push_back(arr);
            }
        }

        return ans;
    }
};
