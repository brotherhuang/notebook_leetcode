"""Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack."""
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0 : return 0
        if len(haystack) == 0: return -1
        for i in range(len(haystack) - len(needle) + 1):
            for j in range(len(needle) + 1):
                if j == len(needle): return i
                if haystack[i + j] != needle[j]: break;
        return -1
