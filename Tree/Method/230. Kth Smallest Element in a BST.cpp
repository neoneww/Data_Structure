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

    int kthSmallest(TreeNode *root, int k)
    {
        int rv = -1;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            TreeNode *left = cur->left;
            if (left == NULL)
            {
                if (--k == 0)
                {
                    rv = cur->val;
                }
                cur = cur->right;
            }
            else
            {
                TreeNode *rightMost = getRightMostNode(left,cur);
                if(rightMost->right == NULL){
                    rightMost->right = cur;
                    cur = cur->left;
                }else{
                    rightMost->right = NULL;
                    if(--k == 0){
                        rv = cur->val;
                    }
                    cur = cur->right;
                }
            }
        }
        return rv;
    }
};
