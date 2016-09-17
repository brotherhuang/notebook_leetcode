"""Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree, """
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        nodeList = []
        res = []
        nodeList.append(root)
        while nodeList :
            if nodeList[-1] : res.append(nodeList[-1].val)
            nextLevel = []
            for node in nodeList:
                if node and node.left:nextLevel.append(node.left)
                if node and node.right : nextLevel.append(node.right)
            nodeList = nextLevel
        return res    
