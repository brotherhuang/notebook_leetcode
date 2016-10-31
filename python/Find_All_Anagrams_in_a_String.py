"""
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
"""
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        if len(s) < len(p) : return res
        diff = [0]*26
        for char in p:
            diff[ord(char) - 97] += 1
        for i in range(len(s) - len(p) + 1):
            if i == 0:
                for j in range(len(p)):
                    diff[ord(s[j]) - 97] -= 1
            else:
                diff[ord(s[i - 1]) - 97] += 1
                diff[ord(s[i + len(p) - 1]) - 97] -= 1
            if diff.count(0) == 26 : res.append(i)
        return res
