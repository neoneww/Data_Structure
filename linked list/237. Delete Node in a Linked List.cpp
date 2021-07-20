class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *forw = node->next,*prev = node;
        while(forw != NULL){
            prev = node;
            node->val = forw->val;
            node = node->next;
            forw = forw->next;
        }
        prev->next =  NULL;
        delete node;
    }
};
