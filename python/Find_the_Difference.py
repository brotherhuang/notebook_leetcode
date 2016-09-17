"""
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
"""
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        mp = {}
        for char in s :
            if mp.has_key(char) :
                mp[char] += 1
            else : mp[char] = 1
        for char in t :
            if not mp.has_key(char): return char
            mp[char] -= 1
            if mp[char] == -1:
                return char
