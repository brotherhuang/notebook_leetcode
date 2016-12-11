/* Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. */
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
        ListNode* current = head;
        while(current && current->next){
            if(current->val == current->next->val) current->next = current->next->next;
            else current = current->next;
        }
        return head;        
    }
};
 
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *cur = head;
        while(cur->next) {
            if(cur->val == cur->next->val) {
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }
};
