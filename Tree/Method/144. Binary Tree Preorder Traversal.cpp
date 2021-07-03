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
class Solution
{
public:
    TreeNode *getRightMostNode(TreeNode *node, TreeNode *curr)
    {
        while (node->right != nullptr && node->right != curr)
        {
            node = node->right;
        }

        return node;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root;
        while (curr != nullptr)
        {
            TreeNode *left = curr->left;
            if (left == nullptr)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *rightMostNode = getRightMostNode(left, curr);
                if (rightMostNode->right == nullptr)
                {                                // thread creation block
                    rightMostNode->right = curr; // thread is created
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {                                   // thread destroy block
                    rightMostNode->right = nullptr; // thread is cut down

                    // ans.push_back(curr->val);

                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
