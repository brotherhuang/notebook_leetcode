/* Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1. */
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
              int listSizeA = 0;
              ListNode* current = headA;
              while(current){
                  listSizeA++;
                  current = current->next;
              }
              int listSizeB = 0;
              current = headB;
              while(current){
                  listSizeB++;
                  current = current->next;
              }
              ListNode* longer;
              ListNode* shorter;
              int diff = abs(listSizeA - listSizeB);
              if(listSizeA >= listSizeB){
                  longer = headA;
                  shorter = headB;
              }
              else{
                  longer = headB;
                  shorter = headA;
              }
              while(diff > 0 ){
                  longer = longer->next;
                  diff --;
              }
              while(longer!= shorter){
                  longer = longer->next;
                  shorter = shorter->next;
              }
              return longer;
    }
};
