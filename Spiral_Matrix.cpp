/* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]. */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(n == 0) return res;
        int m = matrix[0].size();
        int startRow = 0;
        int endRow = n;
        int startCol = 0;
        int endCol = m;
        while(res.size() < n * m){
            for(int i = startCol; i < endCol; i++){
                res.push_back(matrix[startRow][i]);
            }
            if(res.size() == n * m) return res;
            for(int i = startRow + 1; i < endRow; i++){
               res.push_back(matrix[i][endCol-1]);
            }
            if(res.size() == n * m) return res;
            for(int i = endCol - 2; i >= startCol; i--){
                res.push_back(matrix[endRow - 1][i]);
            }
            if(res.size() == n * m) return res;
            for(int i = endRow - 2; i > startRow; i--){
                res.push_back(matrix[i][startCol]);
            }
            if(res.size() == n * m) return res;
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return res;
    }
};
