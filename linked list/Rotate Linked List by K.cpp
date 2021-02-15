/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node, int k)
{
    if(node == NULL || k == 0)
    {
        return node;
    }

    LLNode *temp = node;
    int cnt = 0;

    while(temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    if(k == cnt){
        return node;
    }
    // now we have length of the ll we will move (cnt-k-1)
    cnt = (cnt-k-1);
    temp = node;
    while(cnt--)
    {
        temp = temp->next;
    }
    LLNode *run = node;
    while(run->next != NULL)
    {
        run = run->next;
    }
    run->next = node;
    node = temp->next;
    temp->next = NULL;
    return node;   
}
