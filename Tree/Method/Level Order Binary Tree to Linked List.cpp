/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode *solve(Tree *root)
{
    queue<Tree *> pendingNode;
    pendingNode.push(root);
    LLNode *dummy = new LLNode;
    dummy->val = -1;
    dummy->next = NULL;
    LLNode *cur = dummy;
    while (pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        while (cnt--)
        {
            Tree *front = pendingNode.front();
            pendingNode.pop();
            LLNode *qq = new LLNode;
            qq->val = front->val;
            cur->next = qq;
            cur = cur->next;
            if (front->left != NULL)
            {
                pendingNode.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNode.push(front->right);
            }
        }
    }
    return dummy->next;
}
