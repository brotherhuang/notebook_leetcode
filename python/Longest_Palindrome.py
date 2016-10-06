"""
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
"""
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp = {}
        for char in s:
            if mp.has_key(char):
                mp[char] += 1
            else:
                mp[char] = 1
        maxOdd = 0
        totalLen = 0
        for key in mp:
            if mp[key] % 2 == 0:
                totalLen += mp[key]
            else :
                totalLen += mp[key] - 1
                maxOdd = max(maxOdd, mp[key])
        if maxOdd > 0  : return totalLen + 1
        return totalLen
                
