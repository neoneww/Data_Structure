/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *thead = NULL,*ttail = NULL;

int length(ListNode *node){
    int len = 0;
    while(node != NULL){
        node = node->next;
        len++;
    }
    return len;
}

void addFirst(ListNode *node){
    if(thead == NULL && ttail == NULL){
        thead = node;
        ttail = node;
    }else{
        node->next = thead;
        thead = node;
    }
}
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k <= 1) return head;
        
    ListNode *ohead = NULL,*otail = NULL;
    ListNode *cur = head;
    int len = length(cur);
    cur = head;
        
    while( cur != NULL && len >= k){
        int qq = k;
        while(qq > 0){
            //cout<<cur;
           ListNode *forwa = cur->next;
            cur->next = NULL;
            addFirst(cur);
            cur = forwa;
            qq--;
        }
        if(ohead == NULL && otail == NULL){
            ohead = thead;
            otail = ttail;
        }
        else{
            otail->next = thead;
            otail = ttail;
        }
        thead = NULL;
        ttail = NULL;  
          len -= k;
    }
    
  

    otail->next = cur;
    return ohead;
    }
};
