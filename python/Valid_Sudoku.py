"""
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
"""
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        # check each row
        for row in range(0,9):
            num = [0] * 9
            for col in range(0,9):
                if board[row][col].isdigit():
                    num[int(board[row][col]) - 1] += 1
                    if num[int(board[row][col]) - 1] > 1 : return False
        for col in range(0,9):
            num = [0] * 9
            for row in range(0,9):
                if board[row][col].isdigit():
                    num[int(board[row][col]) - 1] += 1
                    if num[int(board[row][col]) - 1] > 1 : return False


        for brow in range(0,3):
            for bcol in range(0,3):
                num = [0] * 9
                for k in range(0,3):
                    for kk in range(0,3):
                        if board[brow * 3 + k][bcol *3 + kk].isdigit():
                            num[int(board[brow * 3 + k][bcol *3 + kk]) - 1] += 1
                            if num[int(board[brow * 3 + k][bcol *3 + kk]) - 1] > 1 : return False
        return True       
