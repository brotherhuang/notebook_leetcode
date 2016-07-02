/* or vertically. You may assume all four edges of the grid are all surrounded by water.

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
00011 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size();
        if(n == 0) return res;
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    res++;
                    visited[i][j] = true;
                    queue<pair<int,int>> checklist;
                    checklist.push(pair<int,int>(i,j));
                    while(!checklist.empty()){
                            int currentX = checklist.front().first;
                            int currentY = checklist.front().second;
                            checklist.pop();
                            if(currentX > 0 && grid[currentX - 1][currentY] == '1' && !visited[currentX - 1][currentY]){
                                checklist.push(pair<int,int>(currentX - 1,currentY));
                                visited[currentX - 1][currentY] = true;
                            }
                            if(currentX + 1 < n && grid[currentX + 1][currentY] == '1' && !visited[currentX + 1][currentY]){
                                checklist.push(pair<int,int>(currentX + 1,currentY));
                                visited[currentX + 1][currentY] = true;
                            }
                            if(currentY > 0 && grid[currentX][currentY - 1] == '1' && !visited[currentX][currentY - 1]){
                                checklist.push(pair<int,int>(currentX,currentY-1));
                                visited[currentX][currentY - 1] = true;
                            }
                            if(currentY + 1 < m && grid[currentX][currentY + 1] == '1' && !visited[currentX][currentY + 1]){
                                checklist.push(pair<int,int>(currentX,currentY + 1));
                                visited[currentX][currentY + 1] = true;
                            }
                    }
                }
            }
        }
        return res;
    }
};