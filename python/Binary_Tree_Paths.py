"""
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        def findPath(root, current, res):
            if not root : return
            if len(current) > 0 : current = current + "->" + str(root.val)
            else : current = current + str(root.val)
            if not root.left and not root.right : res.append(current)
            findPath(root.left, current, res)
            findPath(root.right, current, res)
        current = ""
        res = []
        findPath(root, current, res)
        return res
