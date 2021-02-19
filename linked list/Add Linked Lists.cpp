/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l0, LLNode* l1)
{
    if(l0 == NULL && l1 == NULL)
    {
        return l0;
    }    

    if(l1 == NULL && l0 != NULL)
    {
        return l0;
    }

    if(l1 != NULL && l0 == NULL)
    {
        return l1;
    }

    LLNode *dummy = new LLNode();

    LLNode *temp = dummy;
    int carry = 0;

    while(l0 != NULL || l1 != NULL || carry != 0)
    {
        int sum = 0;
        if(l0 != NULL)
        {
            sum += l0->val;
            l0 = l0->next;
        }
        if(l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        sum += carry;
        carry = sum/10;
        LLNode *pp = new LLNode;
        pp->val = sum%10;
        temp->next = pp;
        temp = pp;
    }

    return dummy->next;
}
