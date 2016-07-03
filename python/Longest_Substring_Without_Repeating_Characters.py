"""Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

 """

 class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp ={}
        maxLen = 0
        currentLen = 0
        checkIndex = -1
        for i  in range(len(s)):
            if s[i] in mp and mp[s[i]] > checkIndex: checkIndex = mp[s[i]]
            maxLen = max(maxLen, i - checkIndex)
            mp[s[i]] = i
        return maxLen



class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp ={}
        maxLen = 0
        currentLen = 0
        checkIndex = -1
        for i  in range(len(s)):
            if s[i] in mp and mp[s[i]] > checkIndex:
                checkIndex = mp[s[i]]
                maxLen = max(maxLen, currentLen)
                currentLen = i - mp[s[i]]
                mp[s[i]] = i
            else:
                mp[s[i]] = i
                currentLen += 1
        return max(maxLen, currentLen)
