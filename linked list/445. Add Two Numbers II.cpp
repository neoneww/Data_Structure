
class Solution {
public:

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        l1 = reversal(l1);
        l2 = reversal(l2);
        int carr = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while(l1 != NULL || l2 != NULL || carr != 0){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
            }
            if(l2 != NULL){
                sum += l2->val;
            }
            sum += carr;
            ListNode *qq = new ListNode(sum%10);
            carr = sum/10;
            tail->next = qq;
            tail = tail->next;

            if(l1 != NULL){
                l1 = l1->next;
            }

            if(l2 != NULL){
                l2 = l2->next;
            }
        }
        return reversal(dummy->next);
    }
};
