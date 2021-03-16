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
    bool isSymmetric(TreeNode* root)
    {
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);

        while(pendingNode.empty() == false)
        {
            int cnt = pendingNode.size();
            vector<int> temp;
            while(cnt--)
            {
                TreeNode *cur = pendingNode.front();
                pendingNode.pop();

                if(cur->left != NULL)
                {
                    pendingNode.push(cur->left);
                    temp.push_back(cur->left->val);
                }
                else if(cur->left == NULL)
                {
                    temp.push_back(-200);
                }

                if(cur->right != NULL)
                {
                     pendingNode.push(cur->right);
                    temp.push_back(cur->right->val);
                }
                else if(cur->right == NULL)
                {
                    temp.push_back(-200);
                }
            }
            int i = 0,j = temp.size()-1;
            while(i<j)
            {
                if(temp[i] != temp[j])
                {
                    return false;
                }
                i++;j--;
            }
        }

        return true;    
    }
};
