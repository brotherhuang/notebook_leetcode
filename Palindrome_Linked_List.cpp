/* Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space? */
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while (last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};

/*-------------------------------------*/

ListNode reverse(ListNode l) {
if (l == null ||
        l.next == null) {
  return l;
}

ListNode p1 = l,
             p2 = l.next,
             p3 = p2.next;

l.next = null;
while (p2 != null) {
  p3 = p2.next;
  p2.next = p1;
  p1 = p2;
  p2 = p3;
}

return p1;
}
