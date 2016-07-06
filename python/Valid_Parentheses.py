"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not."""
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s is None: return True
        checkList = []
        for char in s:
            if char == '[' or char == '(' or char == '{':
                checkList.append(char)
            else:
                if len(checkList) == 0: return False
                if char == ']' and checkList[-1] != '[': return False
                if char == '}' and checkList[-1] != '{': return False
                if char == ')' and checkList[-1] != '(': return False
                checkList.pop()
        return  len(checkList) == 0   
