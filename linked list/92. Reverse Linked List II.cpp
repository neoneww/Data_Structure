class Solution {
public:
    ListNode *thead = NULL,*ttail = NULL;

    void addFirst(ListNode *head){
        if(thead == NULL && ttail == NULL){
            thead = head;
            ttail = head;
        }else{
            head->next = thead;
            thead = head;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        thead = NULL;ttail = NULL;
        if(head == NULL || head->next == NULL || left == right) return head;
        ListNode *dummy = new ListNode(-1),*taildummy = dummy,*cur = head;
        int num = 1;
        while(cur != NULL){
            ListNode *forw = cur->next;
            cur->next = NULL;
            if(num >= left && num <= right){
                addFirst(cur);
            }else if(num < left){
                taildummy->next = cur;
                taildummy = taildummy->next;
            }else if(num > right){
                if(num == right + 1){
                    taildummy->next = thead;
                    taildummy = ttail;
                    ttail = NULL;thead = NULL;
                    taildummy->next = cur;
                    taildummy = taildummy->next;
                }else{
                    taildummy->next = cur;
                    taildummy = taildummy->next;
                }
            }
            cur = forw;
            num++;
        }
        if(thead != NULL)
        {
            taildummy->next = thead;
        }
        return dummy->next;
    }
};


