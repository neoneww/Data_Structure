/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* a, LLNode* b, int lo, int hi) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    LLNode *cur = new LLNode(-1),*tcur = cur;
    int nums = 0;
    while(a != NULL){
        if(nums >= lo && nums <= hi){
            while(nums<=hi){
                a = a->next;
                nums++;
            }
            tcur->next = b;
            while(tcur->next != NULL){
                tcur = tcur->next;
            }
        }else{
            LLNode *forw = a->next;
            a->next = NULL;
            tcur->next = a;
            tcur = tcur->next;
            a = forw;
        }
        nums++;
    }
    return cur->next;
}
