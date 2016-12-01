"""
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def generateTreesRange(start,end):
            res = []
            if start > end : res.append(None)
            elif start == end: res.append(TreeNode(start))
            else:
                for i in range(start, end+1):
                    left = generateTreesRange(start, i - 1)
                    right = generateTreesRange(i+1 , end)
                    for l in left:
                        for r in right:
                            root = TreeNode(i)
                            root.left = l
                            root.right = r
                            res.append(root)
            return res
        if n < 1 : return []
        return generateTreesRange(1,n)
