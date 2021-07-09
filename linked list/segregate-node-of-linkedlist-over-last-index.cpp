ListNode *segregateOnLastIndex(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;

    ListNode *cur = head,*prev = NULL;

    while(cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    ListNode *qq = cur;
    prev->next = NULL;
    ListNode *temp = head;

    while(temp != NULL){
        ListNode *forw = temp->next;
        temp->next = NULL;
        if(temp->val > cur->val){
            qq->next = temp;
            qq = qq->next;
        }
        temp = forw;
    }
    return cur;

}
