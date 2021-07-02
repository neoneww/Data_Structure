LLNode* midNode(LLNode* head) {
    if (head == NULL) return head;
    LLNode *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

LLNode* mergeTwoLists(LLNode* l1, LLNode* l2) {
    if (l1 == NULL && l2 == NULL) return l1;
    if (l1 == NULL && l2 != NULL) return l2;
    if (l1 != NULL && l2 == NULL) return l1;

    LLNode* dummy = new LLNode(0);
    LLNode* head = dummy;
    LLNode *temp1 = l1, *temp2 = l2;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            head->next = l1;
            head = l1;
            l1 = l1->next;
            head->next = NULL;
        } else {
            head->next = l2;
            head = l2;
            l2 = l2->next;
            head->next = NULL;
        }
    }

    if (l1 == NULL)
        head->next = l2;
    else
        head->next = l1;

    return dummy->next;
}

LLNode* solve(LLNode* head) {
    if (head == NULL || head->next == NULL) return head;

    LLNode* mid = midNode(head);
    LLNode* nHead = mid->next;
    mid->next = NULL;

    return mergeTwoLists(solve(head), solve(nHead));
}
