"""
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
"""
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp = {}
        for char in s :
            if mp.has_key(char) :
                mp[char] += 1
            else : mp[char] = 1
        for i in range(len(s)) :
            if mp[s[i]] == 1 : return i
        return -1    
