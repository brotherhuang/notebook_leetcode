/* Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        if(matrix.size() == 0) return res;
        int m = matrix.size(); int n = matrix[0].size();
        vector<vector<int>> maxLength(m, vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res,findMax(matrix,maxLength,i,j));
            }
        }
        return res;
    }
    int findMax(vector<vector<int> > &matrix, vector<vector<int>>& maxLength, int i, int j){
         if(maxLength[i][j] > 0 ) return maxLength[i][j];
         int maxL = 1;
         if(i > 0 && matrix[i][j] > matrix[i-1][j]) {
             int len = 1 + findMax(matrix,maxLength,i-1,j);
             maxL = max(maxL, len);
         }
         if(i + 1 < matrix.size() && matrix[i][j] > matrix[i+1][j]) {
             int len = 1 + findMax(matrix,maxLength,i+1,j);
             maxL = max(maxL, len);
         }
         if(j+1 < matrix[0].size() && matrix[i][j] > matrix[i][j+1]) {
             int len = 1 + findMax(matrix,maxLength,i,j+1);
             maxL = max(maxL, len);
         }
         if(j > 0 && matrix[i][j] > matrix[i][j-1]) {
             int len = 1 + findMax(matrix,maxLength,i,j-1);
             maxL = max(maxL, len);
         }
         maxLength[i][j] = maxL;
         return maxL;
    }
};