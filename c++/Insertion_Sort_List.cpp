／＊ 
Sort a linked list using insertion sort.
＊／
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(INT_MIN);
        while(head){
            ListNode* cur = head;
            ListNode* p = newHead;
            head = head->next;
            while(p->next && p->next->val <= cur->val){
                p = p->next;
            }
            cur->next = p->next;
            p->next = cur;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};