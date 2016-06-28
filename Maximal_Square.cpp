/* Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4. */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> maxSquare(row, vector<int>(col,0));
        int maxSize = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1') {
                    maxSquare[i][j] = 1;
                    maxSize = 1;
            }
        }
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                    if(maxSquare[i][j] > 0){
                        maxSquare[i][j] = 1 + min(maxSquare[i-1][j],min(maxSquare[i][j-1],maxSquare[i-1][j-1]));
                        maxSize = max(maxSize, maxSquare[i][j]);
                    }
                }
            }
        return maxSize * maxSize;
    }
};
