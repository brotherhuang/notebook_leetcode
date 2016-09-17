"""
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
"""
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: Set[str]
        :rtype: int
        """
        usedWord = set()
        usedWord.add(beginWord)
        current = []
        current.append(beginWord)
        path = 1
        while len(current) > 0 :
            next = []
            for word in current:
                for i in range(len(word)):
                    newWordList = list(word)
                    for char in range(ord('a'), ord('z') + 1):
                        newWordList[i] = chr(char)
                        newWord = ''.join(newWordList)
                        if newWord not in usedWord and newWord in wordList :
                            next.append(newWord)
                            usedWord.add(newWord)
            if endWord in  usedWord :
                return path + 1
            current = next
            path = path + 1
        return 0
