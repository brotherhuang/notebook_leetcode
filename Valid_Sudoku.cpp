/* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid. */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         //check each row
         for(int i = 0; i < 9; i++){
             vector<int> numCount(9,0);
             for(int j = 0; j < 9; j++){
                 if(isdigit(board[i][j])){
                     numCount[board[i][j] - '1']++;
                     if(numCount[board[i][j] - '1'] > 1){
                         return false;
                     }
                 }
             }
         }
         // check each col
         for(int i = 0; i < 9; i++){
             vector<int> numCount(9,0);
             for(int j = 0; j < 9; j++){
                 if(isdigit(board[j][i])){
                     numCount[board[j][i] - '1']++;
                     if(numCount[board[j][i] - '1'] > 1){
                         return false;
                     }
                 }
             }
         }
         // check each block
         for(int i = 0; i < 3; i++){
             for(int j = 0; j < 3; j++){
                 vector<int> numCount(9,0);
                 for(int k = i*3; k < i*3 + 3; k++){
                     for(int kk = j*3; kk < j*3 + 3; kk++){
                         if(isdigit(board[k][kk])){
                             numCount[board[k][kk] - '1']++;
                             if(numCount[board[k][kk] - '1'] > 1){
                                 return false;
                             }
                         }
                     }
                 }
             }
         }
         return true;
    }
};
