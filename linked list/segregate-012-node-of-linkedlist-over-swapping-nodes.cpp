ListNode *segregate012(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode *zeroHead = new ListNode(-1),*oneHead = new ListNode(-1),*twoHead = new ListNode(-1);
    ListNode *zeroTail = zeroHead,*oneTail = oneHead,*twoTail = twoHead;

    ListNode *cur = head;

    while(cur != NULL){
        ListNode *forw = cur->next;
        cur->next = NULL;
        if(cur->val == 0){
            zeroTail->next = cur;
            zeroTail = zeroTail->next;
        }else if(cur->val == 1){
            oneTail->next = cur;
            oneTail = oneTail->next;
        }else{
            twoTail->next = cur;
            twoTail = twoTail->next;
        }
        cur = forw;
    }
    if(zeroTail == zeroHead && oneTail == oneHead) return twoHead->next;
    if(zeroTail == zeroHead && twoTail == twoHead) return oneHead->next;
    if(oneTail == oneHead && twoTail == twoHead) return zeroHead->next;

    if(zeroHead == zeroTail){
        oneTail->next = twoHead->next;
        return oneTail->next;
    }else if(oneHead == oneTail){
        zeroTail->next = twoHead->next;
        return zeroHead->next;
    }else if(twoHead == twoTail){
        zeroTail->next = oneHead->next;
        return zeroTail->next;
    }

    oneTail->next = twoHead->next;
    zeroTail->next = oneHead->next;

    return zeroHead->next;

}
