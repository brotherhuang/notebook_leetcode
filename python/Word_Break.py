"""
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
"""
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        def findBreak(pos, s, possible, wordDict):
            if pos == len(s) : return True
            for i in range(pos, len(s)):
                current = s[pos:i + 1]
                if current in  wordDict and possible[i + 1]:
                    if findBreak(i + 1, s, possible, wordDict): return True
                    possible[i + 1] = False
            return False
        possible = [True] * (len(s)+1)
        return findBreak(0,s, possible, wordDict)    
