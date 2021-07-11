class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* bx = new ListNode(-1),*ax = new ListNode(-1);
        ListNode* bt = bx,*at = ax;
        ListNode *cur = head;

        while(cur != NULL){
            ListNode *forw = cur->next;
            cur->next = NULL;
            if(cur->val < x){
                bt->next = cur;
                bt = bt->next;
            }else{
                at->next = cur;
                at = at->next;
            }
            cur = forw;
        }
        bt->next = ax->next;
        return bx->next;
    }
};
