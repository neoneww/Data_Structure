/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
 LLNode *thead = NULL,*ttail = NULL;

    void addFirst(LLNode *head){
        if(thead == NULL && ttail == NULL){
            thead = head;
            ttail = head;
        }else{
            head->next = thead;
            thead = head;
        }
    }

    LLNode* solve(LLNode* head, int left, int right) {
        thead = NULL;ttail = NULL;
        if(head == NULL || head->next == NULL || left == right) return head;
        LLNode *dummy = new LLNode(-1),*taildummy = dummy,*cur = head;
        int num = 0;
        while(cur != NULL){
            LLNode *forw = cur->next;
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
