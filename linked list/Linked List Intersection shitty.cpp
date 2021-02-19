/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l1, LLNode* l2)
{
    if(l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
     if(l1 != NULL && l2 == NULL)
    {
        return NULL;
    }
     if(l1 == NULL && l2 != NULL)
    {
        return NULL;
    }
    set<int> pp;
    LLNode *temp1 = l1;
    LLNode *temp2 = l2;
    LLNode *temp = new LLNode();
    LLNode *dif = temp;
    while(temp1 != NULL)
    {
        pp.insert(temp1->val);
        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        auto pos = pp.find(temp2->val);

        if( pos != pp.end())
        {
            LLNode *qq = new LLNode();
            qq->val = temp2->val;
            dif->next = qq;
            dif = qq;
        }
        temp2 = temp2->next;
    }

    return temp->next;
}
