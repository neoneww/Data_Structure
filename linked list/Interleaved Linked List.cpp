LLNode* solve(LLNode* l0, LLNode* l1) {
    if (l0 == NULL) return l1;
    if (l1 == NULL) return l0;

    LLNode* head = l0;

    while (l0 != NULL && l1 != NULL) {
        LLNode *temp1 = l0->next, *temp2 = l1->next;
        l0->next = l1;
        if(temp1 != NULL){
         l1->next = temp1;
        }
        l0 = temp1;
        l1 = temp2;
    }
    if (l0 == NULL && l1 == NULL) return head;

    // if(l0 == NULL){
    //     LLNode *qq = head;
    //     while(head->next != NULL){
    //         head = head->next;
    //     }
    //     head->next = l1;
    // }

    return head;
}
