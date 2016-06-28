/* According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems? */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0){
            return;
        }
       vector<vector<int>> nextBoard(board.size(),vector<int>(board[0].size(),0));
       for(int i = 0; i < board.size(); i++){
           for(int j = 0; j < board[0].size(); j++){
               int startI = (i - 1 >= 0)? i-1:i;
               int endI = (i + 1 < board.size())? i+1:i;
               int startJ = (j - 1 >= 0)? j-1:j;
               int endJ = (j + 1 < board[0].size())?j+1:j;
               int count = -board[i][j];
               for(int ii = startI; ii <= endI; ii++){
                   for(int jj = startJ; jj <= endJ; jj++){
                       count += board[ii][jj];
                   }
               }
           if(board[i][j] == 1) {
             if(count < 2) {nextBoard[i][j] = 0;}
             else if(count < 4) {nextBoard[i][j] = 1;}
             else {nextBoard[i][j] = 0;}
           }
           else{
               if(count == 3) {nextBoard[i][j] = 1;};
           }
         }
       }
       board = nextBoard;
    }
};
