/* Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5. */

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
       ListNode* removeNthFromEnd(ListNode* head, int n) {
           ListNode *pre, *cur;
           pre = head;
           cur = head;
           int step = 0;
           while(step < n && cur ){
               step ++;
               cur = cur->next;
           }
           if(step == n && cur == NULL){
               head = head->next;
               delete pre;
               return head;
           }
           while(cur->next){
               pre = pre->next;
               cur = cur->next;
           }
           ListNode* temp = pre->next;
           pre->next = temp->next;
           delete temp;
           return head;
       }
   };
