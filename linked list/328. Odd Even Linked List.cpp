class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *oid = new ListNode(-1),*eid = new ListNode(-1);
        ListNode *otail = oid,*etail = eid;
        ListNode *cur = head;
        int num = 0;
        while(cur != NULL){
            ListNode *forw = cur->next;
            cur->next = NULL;
            if(num%2 == 0){
                etail->next = cur;
                etail = etail->next;
            }else{
                otail->next = cur;
                otail = otail->next;
            }
            cur = forw;
            num++;
        }
        etail->next = oid->next;
        return eid->next;
    }
};
