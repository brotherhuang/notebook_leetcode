/* Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? /*
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
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        do{
            if(!fast->next){return false;}
            fast = fast->next;
            if(!fast->next){return false;}
            fast = fast->next;
            if(!slow->next){return false;}
            slow = slow->next;
        }while(fast != slow);
        return true;
    }
};
