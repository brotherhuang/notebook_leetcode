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
        ListNode * newhead = new ListNode(0);
        while (head){
            ListNode * tmp = newhead->next;
            newhead->next = head;
            head = head->next;
            newhead->next->next = tmp;
        }
        return newhead->next;
    }
};


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
