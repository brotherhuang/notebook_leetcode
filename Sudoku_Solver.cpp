/* Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.

Subscribe to see which companies asked this question */
class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int row, int num){
        for(int col = 0; col < 9; col++){
            if(board[row][col] == '0' + num){
                return true;
            }
        }
        return false;
    }
    bool checkCol(vector<vector<char>>& board, int col, int num){
        for(int row = 0; row < 9; row++){
            if(board[row][col] == '0' + num){
                return true;
            }
        }
        return false;
    }
    bool checkBox(vector<vector<char>>& board, int startRow, int startCol, int num){
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                if(board[row+startRow][col + startCol] == '0' + num){
                    return true;
                }
            }
        }
        return false;
    }
    bool findNext(vector<vector<char>>& board, int &row, int&col){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool validSolution(vector<vector<char>>& board){
        int row, col;
        if(!findNext(board,row,col)) return true;
        for(int num = 1; num <= 9 ; num++){
            if(!checkRow(board,row,num) && !checkCol(board,col,num) && !checkBox(board,row - row % 3,col - col % 3,num)){
                board[row][col] = '0' + num;
                if(validSolution(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
         validSolution(board);
    }
};
