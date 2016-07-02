""" Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets. """
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t): return False
        listS = [0] * 26
        listT = [0] * 26
        for i in s:
            listS[ord(i) -ord('a')] += 1
        for i in t:
            listT[ord(i) -ord('a')] += 1
        return listS == listT
