/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time. */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>  minPath(grid.size(), vector<int>(grid[0].size(),0));
        minPath[0][0] = grid.back().back();
        int m = minPath.size();
        int n = minPath[0].size();
        for(int i = 0;  i< m; i++){
            for(int j = 0; j < n; j++){
                if(i+ j > 0){
                    int nodeVal = grid[m - i - 1][n - j - 1];
                    if(i == 0){
                        minPath[i][j] = minPath[i][j-1] + nodeVal;
                        continue;
                    }
                    if(j == 0){
                        minPath[i][j] = minPath[i-1][j] + nodeVal;
                        continue;
                    }
                    minPath[i][j] = min(minPath[i][j-1] + nodeVal, minPath[i][j] = minPath[i-1][j] + nodeVal);
                }
            }
        }
        return minPath.back().back();
    }
};
