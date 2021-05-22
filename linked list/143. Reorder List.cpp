/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // this function will return the head of the reversed list
    ListNode *reverseList(ListNode *cur)
    {
        ListNode *prev = NULL, *temp;

        while (cur != NULL)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

    ListNode *returnMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void reorderList(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return;

        ListNode *l1 = head;                        
        ListNode *mid = returnMid(head);   //mid node 
        ListNode *temp = mid->next;

        mid->next = NULL;    //our list 1 is alone now;

        ListNode *l2 = reverseList(temp);   // reverse list;

        ListNode *p1 = NULL,*p2 = NULL;

        while(l2 != NULL)
        {
            p1 = l1->next;
            p2 = l2->next;  

            l1->next = l2;
            l2->next = p1;

            l1 = p1;
            l2 = p2;
        }
    }
};
