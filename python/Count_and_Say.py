"""
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
"""
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = []
        if n < 1 : return res
        current = "1"
        for i in range(2, n+1):
            newStr = ""
            count = 1
            num = current[0]
            for j in range(1, len(current)):
                if current[j] == num:
                    count += 1
                else:
                    newStr += str(count)
                    newStr += num
                    count = 1
                    num = current[j]
            newStr += str(count)
            newStr += num
            current = newStr
        return current    
