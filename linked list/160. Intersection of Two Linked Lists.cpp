class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA, *temp2 = headB;
        int len1 = 0, len2 = 0;
        while(temp1 != NULL || temp2 != NULL){
            if(temp1 != NULL){
                len1++;
                temp1 = temp1->next;
            }

            if(temp2 != NULL){
                len2++;
                temp2 = temp2->next;
            }
        }

        temp1 = headA;
        temp2 = headB;

        if(len1 > len2){
            int q = len1 - len2;
            while(q--){
                temp1 = temp1->next;
            }
        }else if(len2 > len1){
            int q = len2 - len1;
            while(q--){
                temp2 = temp2->next;
            }
        }

        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
};
