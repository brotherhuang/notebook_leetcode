""" Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999. """
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        def toNum(c):
            if c == 'I': return 1
            if c == 'V': return 5
            if c == 'X': return 10
            if c == 'L': return 50
            if c == 'C': return 100
            if c == 'D': return 500
            return 1000
        if s is None : return 0
        res = 0
        perNum = 0
        for i in s:
            current = toNum(i)
            res += current
            if current > perNum:
                res -= 2 * perNum
            perNum = current
        return res
