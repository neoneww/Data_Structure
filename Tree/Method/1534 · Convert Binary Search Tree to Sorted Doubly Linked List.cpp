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
     * @param root: root of a tree
     * @return: head node of a doubly linked list
     */
    TreeNode *getRightMost(TreeNode *cur, TreeNode *par) {
        while (cur->right != NULL && cur->right != par) {
            cur = cur->right;
        }

        return cur;
    }
    TreeNode *treeToDoublyList(TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        TreeNode *cur = root, *prev = dummy;
        while (cur != NULL) {
            TreeNode *leftNode = cur->left;
            if (leftNode == NULL) {
                prev->right = cur;
                cur->left = prev;
                prev = prev->right;
                cur = cur->right;
            } else {
                TreeNode *rightNode = getRightMost(leftNode, cur);
                if (rightNode->right == NULL) {
                    rightNode->right = cur;
                    cur = cur->left;
                } else {
                    rightNode->right = NULL;
                    prev->right = cur;
                    cur->left = prev;
                    prev = prev->right;
                    cur = cur->right;
                }
            }
        }

        TreeNode *head = dummy->right;
        dummy->right = head->left = NULL;

        head->left = prev;
        prev->right = head;

        return head;
    }
};
