/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list. */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * first = head;
        ListNode * second = head;
        while(first != NULL && second != NULL){
            first = first->next;
            second = second->next;
            if(second != NULL) second = second->next;
            if(first == second)  break;
        }
        if(second == NULL) return NULL;
        first = head;
         while(first!=second){
             first = first->next;
             second = second->next;
         }
        return second;
    }
};
