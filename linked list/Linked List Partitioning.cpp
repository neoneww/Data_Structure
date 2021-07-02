/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode *solve(LLNode *node, int k) {
    if (node == NULL || node->next == NULL) return node;
    LLNode *head1 = new LLNode(-1);
    LLNode *head2 = new LLNode(-1);
    LLNode *head3 = new LLNode(-1);

    head1->next = NULL;
    head2->next = NULL;
    head3->next = NULL;

    LLNode *temp1 = head1, *temp2 = head2, *temp3 = head3;

    while (node != NULL) {
        LLNode *cur = node->next;
        if (node->val < k) {
            temp1->next = node;
            node->next = NULL;
            temp1 = node;
        } else if (node->val == k) {
            temp2->next = node;
            node->next = NULL;
            temp2 = node;
        } else {
            temp3->next = node;
            node->next = NULL;
            temp3 = node;
        }
        node = cur;
    }

    LLNode *finAns = new LLNode(-1);
    finAns->next = head1->next;
    LLNode *qq = finAns;
    while (qq->next != NULL) {
        qq = qq->next;
    }

    qq->next = head2->next;

    while (qq->next != NULL) {
        qq = qq->next;
    }

    qq->next = head3->next;
    return finAns->next;
}
