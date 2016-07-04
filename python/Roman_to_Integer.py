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

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp = {}
        mp['M'] = 1000
        mp['CM'] = 900
        mp['D'] = 500
        mp['CD'] = 400
        mp['C'] = 100
        mp['XC'] = 90
        mp['L'] = 50
        mp['XL'] = 40
        mp['X'] = 10
        mp['IX'] = 9
        mp['V'] = 5
        mp['IV'] = 4
        mp['I'] = 1
        startPos = 0
        res = 0
        while startPos < len(s):
            if s[startPos: startPos + 2] in mp:
                res += mp[s[startPos: startPos + 2]]
                startPos += 2
            else:
                res += mp[s[startPos: startPos + 1]]
                startPos += 1
        return res
            
