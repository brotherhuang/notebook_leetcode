"""
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
"""
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(i, j, pos, word, board, mask):
            if pos == len(word) - 1 : return True
            candiates = []
            if i - 1 >= 0 and mask[i-1][j] == False :
                candiates.append([i-1,j])
            if i + 1 < len(board) and mask[i+1][j] == False :
                candiates.append([i+1,j])
            if j - 1 >= 0 and mask[i][j-1] == False :
                candiates.append([i,j - 1])
            if j + 1 < len(board[0]) and mask[i][j + 1] == False :
                candiates.append([i,j + 1])
            for can in candiates:
                if board[can[0]][can[1]] == word[pos + 1] :
                    mask[can[0]][can[1]] = True
                    if dfs(can[0], can[1], pos + 1, word, board, mask) : return True
                    mask[can[0]][can[1]] = False
            return False
        if len(board) == 0: return False
        mask = [x[:] for x in [[False]*len(board[0])]*len(board)]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    mask[i][j] = True;
                    if dfs(i, j, 0, word, board, mask) : return True
                    mask[i][j] = False;
        return False    
