/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

LLNode *reverseList(LLNode *node)
{
    LLNode *curr = node;
    LLNode *prev = NULL;
    while(curr != NULL)
    {
        LLNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int solve(LLNode* node, int k) {
    if(node->next == NULL)
    {
        return node->val;
    }

    node = reverseList(node);
    while(k--)
    {
        node = node->next;
    }

    return node->val;
}
