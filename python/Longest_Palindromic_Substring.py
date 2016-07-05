"""Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring."""
class Solution(object):
    def getlongestpalindrome(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1; r += 1
        return s[l+1 : r]
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s is None: return s
        res = ''
        for i in range(len(s)):
            s1 = self.getlongestpalindrome(s, i, i)
            if len(s1) > len(res):
                res = s1
            s2 = self.getlongestpalindrome(s, i, i + 1)
            if len(s2) > len(res):
                res = s2
        return res    
