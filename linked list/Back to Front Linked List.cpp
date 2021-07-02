LLNode *mid(LLNode *head) {
    if (head == NULL) return head;
    LLNode *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

LLNode* reverseList(LLNode *head) {
    if (head == NULL) return head;
    LLNode *prev = NULL, *cur = head;

    while (cur != NULL) {
        LLNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return prev;
}

LLNode *solve(LLNode *head) {
    if (head == NULL || head->next == NULL) return head;
    LLNode *temp = head, *newHead = head;
    temp = mid(temp);
    newHead = temp->next;
    temp->next = NULL;
    newHead = reverseList(newHead);

    LLNode *head1 = head, *head2 = newHead;

    while (head2 != NULL) {
        LLNode *pp = head1->next, *qq = head2->next;
        head2->next = head1;
        head1->next = qq;
        head2 = qq;
        head1 = pp;
    }
  
    if(head1 != NULL){
        LLNode *aa = newHead;
        while(aa->next != NULL){
            aa = aa->next;
        }
        aa->next = head1;
    }
    return newHead;
}
