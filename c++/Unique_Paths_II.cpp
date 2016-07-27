/*Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n,1);
        for(int j=1; j<n; j++) {
            if(obstacleGrid[0][j]==1)
                dp[j] = 0;
            else
                dp[j] = dp[j-1];
        }

        for(int i=1; i<m; i++) {
            dp[0] = obstacleGrid[i][0]==1 ? 0 : dp[0];
            for(int j=1; j<n; j++) {
                dp[j] = obstacleGrid[i][j]==1 ? 0 : dp[j-1] + dp[j];
            }
        }
        return dp[n-1];
    }
};
