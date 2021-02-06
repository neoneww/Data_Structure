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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }

        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        ans.push_back(root->val);
        while(pendingNode.empty() == false)
        {
            int cnt = pendingNode.size();
            vector<int> inter;
            while(cnt--)
            {
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                    inter.push_back(front->right->val);
                }

                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                    inter.push_back(front->left->val);
                }
            }

            if(inter.size() != 0)
            {
                ans.push_back(inter[0]);
            }
        }

        return ans;
    }
};


//right side view of the binary tree (boring)
