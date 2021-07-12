ListNode *reversal(ListNode *head){
    ListNode *prev = NULL;
    while(head != NULL){
        ListNode *forw = head->next;
        head->next = prev;
        prev = head;
        head = forw;
    }
    return prev;
}


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        l1 = reversal(l1);
        l2 = reversal(l2);
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;    //cause at max sum 18
            carry = sum/10;
            ListNode *temp = new ListNode(sum%10);
            tail->next = temp;
            tail = tail->next;
        }
        ListNode *head = dummy->next;
        dummy->next = NULL;
        head = reversal(head);
        return head;
}
