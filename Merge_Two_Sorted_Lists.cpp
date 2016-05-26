/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.*/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(true){
            if(!l1){
                cur->next = l2;
                break;
            }
            if(!l2){
                cur->next = l1;
                break;
            }
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        return res->next;
    }
};
