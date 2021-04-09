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
class Solution {
public:

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow=reverse(slow); 
        fast = head;
        while(slow) { 
            if(fast->val != slow->val)
                return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) { 
        ListNode* prev;
        ListNode* cur;
        ListNode* next;
        prev = NULL;
        cur = head;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
