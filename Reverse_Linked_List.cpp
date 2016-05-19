/* Reverse a singly linked list. */
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
    ListNode* reverseList(ListNode* head) {
        vector<int> vallist;
        ListNode* node = head;
        while(node){
            vallist.push_back(node->val);
            node = node->next;
        }
        node = head;
        int count = vallist.size() - 1;
        while(node){
            node->val = vallist[count];
            node = node->next;
            count--;
        }
        return head;
    }
};
