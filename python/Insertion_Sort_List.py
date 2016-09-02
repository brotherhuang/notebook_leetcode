"""
Sort a linked list using insertion sort.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        newHead = ListNode(0)
        while head :
            cur = head
            p = newHead
            head = head.next
            while p.next and p.next.val <= cur.val:
                p = p.next
            cur.next = p.next
            p.next = cur
        head = newHead.next
        return head