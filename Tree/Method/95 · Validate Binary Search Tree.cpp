/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
    public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    TreeNode *getRightMost(TreeNode *cur, TreeNode *par) {
        while (cur->right != NULL && cur->right != par) {
            cur = cur->right;
        }

        return cur;
    }
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        long prev = -(long)1e13;
        TreeNode *cur = root;  // never loose the root

        while (cur != NULL) {
            TreeNode *leftNode = cur->left;
            if (leftNode == NULL) {
                if (prev >= cur->val) return false;
                prev = cur->val;
                cur = cur->right;
            } else {
                TreeNode *rightNode = getRightMost(leftNode, cur);
                if (rightNode->right == NULL) {
                    rightNode->right = cur;
                    cur = cur->left;
                } else {
                    rightNode->right = NULL;
                    if (prev >= cur->val) return false;
                    prev = cur->val;
                    cur = cur->right;
                }
            }
        }

        return true;
    }
};
