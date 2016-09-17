"""
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
] """
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        nodeList = []
        res = []
        nodeList.append(root)
        while nodeList :
            cur = []
            nextLevel = []
            for node in nodeList:
                if node : cur.append(node.val)
                if node and node.left:nextLevel.append(node.left)
                if node and node.right : nextLevel.append(node.right)
            nodeList = nextLevel
            if cur : res.append(cur)
        return res           
