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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode *mid = returnMid(head);
        ListNode *temp = mid->next;
        mid->next = NULL;

        ListNode *revhead = reverseList(temp);
        ListNode *curhead = head;
        ListNode *rehead = revhead;

        int cnt1 = 0, cnt2 = 0;

        while (rehead != NULL)
        {
            cnt1++;
            rehead = rehead->next;
        }

        while (cnt1--)
        {
            if (revhead->val != curhead->val)
            {
                // cout<<revhead->val<<" "<<curhead->val<<"\n";
                return false;
            }

            revhead = revhead->next;
            curhead = curhead->next;
        }

        return true;
    }
};
