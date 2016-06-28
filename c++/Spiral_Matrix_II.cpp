/* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
] */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0){
            return res;
        }
        res.resize(n,vector<int>(n,0));
        int toalCount = 0;
        int start = 0;
        int end = n;
        int rowIndex = 0;
        int colIndex = n-1;
        while(toalCount < n*n){
            for(int i = start; i < end; i++){
                toalCount ++;
                res[rowIndex][i] = toalCount;
            }
            for(int i = start + 1; i < end; i++){
                toalCount ++;
                res[i][colIndex] = toalCount;
            }
            for(int i = end - 2; i >= start; i--){
                toalCount ++;
                res[n - 1 - rowIndex][i] = toalCount;
            }
            for(int i = end - 2; i > start; i--){
                toalCount ++;
                res[i][n - 1 - colIndex] = toalCount;
            }
            start++;
            end--;
            rowIndex++;
            colIndex--;
        }
        return res;
    }
};
