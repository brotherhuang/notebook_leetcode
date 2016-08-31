"""
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...

"""
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def checkRow(row, num):
            for i in range(0,9):
                if board[row][i] == num : return False
            return True
        def checkCol(col, num):
            for i in range(0,9):
                if board[i][col] == num: return False
            return True
        def checkBlock(row,col, num):
            for k in range(0, 3):
                for kk in range(0, 3):
                    if board[(row/3)*3+k][(col/3)*3+kk] == num: return False
            return True

        def findNext():
            for i in range(0,9):
                for j in range(0,9):
                    if board[i][j] == '.': return True, i, j
            return False, -1, -1

        def findSolution():
            hasNext, row, col = findNext()
            if not hasNext : return True
            if hasNext:
                for i in '123456789':
                    if checkRow(row, i) and  checkCol(col, i) and checkBlock(row, col, i):
                        board[row][col] = i
                        if findSolution() : return True
                        board[row][col] = '.'
            return False
        findSolution()  
