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

    int length(ListNode *head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = length(head);
        k = k%len;
        len = len - k;
        if(len == 0) return head;
        len--;
        ListNode *temp = head;

        while(len--){
            temp = temp->next;
        }

        ListNode *forw = temp->next;
        ListNode *newHead = forw;
        if(forw == NULL) return head;
        while(forw->next != NULL){
            forw = forw->next;
        }

        temp->next = NULL;
        forw->next = head;

        return newHead;

    }
};
