ListNode *segregate01(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode *zeroHead = new ListNode(-1),*oneHead = new ListNode(-1);
    ListNode *zeroTail = zeroHead,*oneTail = oneHead;

    while(head != NULL){
        ListNode *forw = head->next;
        head->next = NULL;
        if(head->val == 0){
            zeroTail->next = head;
            zeroTail = zeroTail->next;
        }else{
            oneTail->next = head;
            oneTail = oneTail->next;   
        }
        head = forw;
    }
    if(zeroHead == zeroTail) return oneHead->next;
    if(oneHead == oneTail) return zeroHead->next;
    zeroTail->next = oneHead->next;
    return zeroHead->next;
}
