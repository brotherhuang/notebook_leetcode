"""
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
"""
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def solver(pos, row, n, res):
            if row == n :
                cur = []
                for i in range(n):
                    cur.append('.' * pos[i] + 'Q' + '.' * (n - 1 - pos[i]))
                res.append(cur)
            for i in range(n):
                valid = True
                for j in range(len(pos)):
                    if i == pos[j] or abs(i - pos[j]) == row - j:
                        valid = False
                        break
                if valid:
                    pos.append(i)
                    solver(pos, row + 1, n, res)
                    pos.pop()
        res= []
        pos = []
        solver(pos, 0, n, res)
        return res