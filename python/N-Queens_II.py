"""
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.



Subscribe to see which companies asked this question
"""
class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        def solver(pos, row, n, res):
            if row == n :
                res[0] += 1
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
        res = [0]
        pos = []
        solver(pos, 0, n, res)
        return res[0]