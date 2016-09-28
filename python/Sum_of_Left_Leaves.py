"""
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root, isleft, sum):
            if not root : return
            if not root.left and not root.right and isleft :
                sum[0] = sum[0] + root.val
                return
            dfs(root.left, True, sum)
            dfs(root.right,False, sum)
        sum = [0]
        dfs(root, False,sum)
        return sum[0]
            
