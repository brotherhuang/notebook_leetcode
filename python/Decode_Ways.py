"""
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
"""
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0 or s[0] == '0' : return 0
        res = [0] * (len(s) + 1)
        if s[-1] != '0' : res[-2] = 1
        if len(s) > 1 and s[-2] != '0' and int(s[-2:]) < 27 : res[-1] = 1
        for i in range(len(s) - 2, -1, -1):
            if s[i] != '0':
                res[i] += res[i+1]
                if int(s[i:i+2]) < 27:
                    res[i] += res[i+2]
        return res[0]            
