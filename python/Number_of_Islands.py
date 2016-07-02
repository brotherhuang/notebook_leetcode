""" Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3 """

from collections import deque
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        res = 0
        n = len(grid)
        if n == 0: return res
        m = len(grid[0])
        visited = [[False] * m for x in range(n)] 
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and visited[i][j] == False:
                    res += 1
                    visited[i][j] = True
                    q = deque([[i,j]])
                    while q:
                        x,y = q.popleft()
                        if x > 0 and grid[x-1][y] == '1' and visited[x - 1][ y] == False: 
                            visited[x - 1][ y] = True
                            q.append([x-1,y])
                        if x + 1 < n and grid[x + 1][y] == '1' and visited[x + 1][ y] == False: 
                            visited[x + 1][ y] = True
                            q.append([x + 1,y])
                        if y > 0 and grid[x][y - 1] == '1' and visited[x][ y - 1] == False: 
                            visited[x][ y - 1] = True
                            q.append([x,y-1])
                        if y  + 1 < m and grid[x][y+1] == '1' and visited[x][y + 1] == False: 
                            visited[x][ y + 1] = True
                            q.append([x,y + 1])
        return res