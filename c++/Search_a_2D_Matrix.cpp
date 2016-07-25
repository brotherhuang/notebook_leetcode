/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = n*m - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};
