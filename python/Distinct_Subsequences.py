"""
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. """
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        if len(s) == 0 : return 0
        if len(t) == 0 : return 0
        mp = {}
        for i in range(len(s)):
            if mp.has_key(s[i]):
                mp[s[i]].append(i)
            else:mp[s[i]] = [i]
        for char in t:
            if not mp.has_key(char):
                return 0
        preIndex = mp[t[-1]]
        prePath = [1] * len(preIndex)
        total = len(preIndex)
        for i in range(len(t) - 1):
            curIndex = mp[t[len(t) - i - 2]]
            curPath = [0] * len(curIndex)
            total = 0;
            for j in range(len(curIndex)):
                for k in range(len(preIndex)):
                    if curIndex[j] < preIndex[k]:
                        curPath[j] += prePath[k]
                        total += prePath[k]
            if total == 0 : return 0
            preIndex = curIndex
            prePath = curPath
        return total
