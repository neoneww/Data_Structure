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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev = NULL;
        ListNode *cur = list1;
        ListNode *tail2 = list2;
        while(tail2->next != NULL){
            tail2 = tail2->next;
        }
        int num = 0;
        while(cur != NULL){
            if(num == a){
                prev->next = list2;
                while(num < b){
                    prev = cur;
                    cur = cur->next;
                    num++;
                }
                tail2->next = cur->next;
                break;
            }
            prev = cur;
            cur = cur->next;
            num++;
        }
        return list1;
    }
};

