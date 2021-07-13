class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     if(l1 == NULL && l2 == NULL) return l1;
    if(l1 == NULL && l2 != NULL) return l2;
    if(l1 != NULL && l2 == NULL) return l1;

    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    ListNode *temp1 = l1,*temp2 = l2;

    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            head->next = l1;
            head = l1;
            l1 = l1->next;
            head->next = NULL;
        }else{
            head->next = l2;
            head = l2;
            l2 = l2->next;
            head->next = NULL;
        }
    }
        
        if(l1 == NULL) head->next = l2;
        else head->next = l1;

    return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head,*fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = slow->next;
        slow->next =  NULL;
        return mergeTwoLists(sortList(head),sortList(head1));
    }
};
