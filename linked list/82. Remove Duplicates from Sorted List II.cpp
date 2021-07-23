class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy,*cur = head;
        dummy->next = head;

        while(cur != NULL){
            bool looprun = false;
            while(cur->next != NULL && prev->next->val == cur->next->val){
                cur = cur->next;
                looprun = true;
            }
                if(looprun == false){
                prev = prev->next;
                cur = cur->next;
                prev->next = cur;
            }else{
                prev->next = cur->next;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
