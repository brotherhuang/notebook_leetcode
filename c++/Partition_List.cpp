/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
ListNode left(0), right(0);
ListNode *l = &left, *r = &right;

while(head){
    ListNode* & ref = head->val < x ? l : r;
    ref->next = head;
    ref = ref->next;

    head = head->next;
}
l->next = right.next;
r->next = NULL;
return left.next;   
