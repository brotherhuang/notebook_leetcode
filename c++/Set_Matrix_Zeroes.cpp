/* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         if(matrix.size() == 0) return;
         vector<bool> zeroRow(matrix.size(),false);
         vector<bool> zeroCol(matrix[0].size(),false);
         for(int i = 0; i < matrix.size(); i++){
             for(int j = 0; j < matrix[i].size(); j++){
                 if(matrix[i][j] == 0){
                     zeroRow[i] = true;
                     zeroCol[j] = true;
                 }
             }
         }
         for(int i = 0; i < matrix.size(); i++){
             for(int j = 0; j < matrix[i].size(); j++){
                 if(zeroRow[i] || zeroCol[j] ){
                     matrix[i][j] = 0;
                 }
             }
         }
    }
};
