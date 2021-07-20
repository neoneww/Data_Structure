class Solution {
private:
    ListNode* h;
    int count;
    
public:
    
 
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h = head;
        ListNode* h1 = h;
        count = 0;
        while(h1){
            count++;
            h1 = h1->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        int random = rand() % count;
        
        ListNode* h1 = h;
        
        while(random--){
            h1 = h1->next;
        }
        
        return h1->val;
        
    }
};
