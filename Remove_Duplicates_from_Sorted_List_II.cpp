/* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.*/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead;
        ListNode* current = head;
        bool duplicate = false;
        while(current){
            if(current->next && current->val == current->next->val){
                duplicate = true;
                current->next = current->next->next;
            }
            else if(duplicate){
                pre->next = current->next;
                current = pre->next;
                duplicate = false;
            }
            else{
                pre = current;
                current = current->next;
            }
        }
        head = newHead->next;
        return head;
    }
};
