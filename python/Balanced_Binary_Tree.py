"""Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. """
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def maxDepth(root):
            if not root : return 0
            return 1 + max(maxDepth(root.left), maxDepth(root.right))
        if not root : return True
        if abs(maxDepth(root.left) - maxDepth(root.right)) > 1 :  return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
