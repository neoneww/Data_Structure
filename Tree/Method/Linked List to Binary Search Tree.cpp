Tree* solve(LLNode* head) {
    if (!head) return NULL;
    if (!head->next) return new Tree(head->val);
    LLNode* slow = head;
    LLNode* fast = head->next;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    LLNode* mid = slow->next;
    slow->next = NULL;
    Tree* root = new Tree(mid->val);
    root->left = solve(head);
    root->right = solve(mid->next);
    return root;
}
