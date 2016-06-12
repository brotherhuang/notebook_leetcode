/* Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.

Subscribe to see which companies asked this question */
class Solution {
public:
    vector<char> findCandidate(vector<vector<char>> board, int row, int col){
        vector<char> candidate(9,true);
        for(int i = 0; i < 9 ; i ++){
             candidate[board[row][i] - '1'] = false;
             candidate[board[i][col] - '1'] = false;
        }
        int blockRow = row / 3;
        int blockCol = col / 3;
        for(int i = blockRow * 3; i < blockRow * 3 + 3; i++){
            for(int j = blockCol * 3 ; j < blockCol *3 + 3; j++){
                candidate[board[i][j] - '1'] = false;
            }
        }
        vector<char> res;
        for(int i = 0; i < candidate.size(); i++){
            if(candidate[i]) res.push_back('1' + i);
        }
        return res;
    }
    bool findSolution(vector<vector<char>>& board, int pos){
        if(pos == 81) return true;
        int row = pos/9;
        int col = pos%9;
        if(board[row][col]!= '.') return findSolution(board,pos + 1);
        vector<char> candidates = findCandidate(board,row,col);
        for(int i = 0; i < candidates.size(); i++){
            board[row][col] = candidates[i];
            if(findSolution(board,pos+1)) return true;
            board[row][col] = '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
         findSolution(board,0);
    }
};