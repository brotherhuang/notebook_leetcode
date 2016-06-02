/*  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return ;
         vector<vector<bool>> checked(board.size(), vector<bool>(board[0].size(),false));
         for(int i = 0; i < board.size(); i++){
             for(int j = 0; j < board[0].size(); j++){
                 if(!checked[i][j]) {
                     if(board[i][j] == 'X'){
                         checked[i][j] = true;
                     }
                     else{
                         vector<int> CheckX;
                         vector<int> CheckY;
                         CheckX.push_back(i);
                         CheckY.push_back(j);
                         bool needAdd = true;
                         while(needAdd){
                             needAdd = false;
                             for(int k = 0; k < CheckX.size(); k++){
                                 if(CheckX[k] - 1 >= 0 && !checked[CheckX[k] - 1][CheckY[k]] && board[CheckX[k] - 1][CheckY[k]] == 'O'){
                                         CheckX.push_back(CheckX[k] - 1);
                                         CheckY.push_back(CheckY[k]);
                                         checked[CheckX[k] - 1][CheckY[k]] = true;
                                         needAdd = true;
                                 }
                                 if(CheckX[k] + 1 < board.size() && !checked[CheckX[k] + 1][CheckY[k]] && board[CheckX[k] + 1][CheckY[k]] == 'O'){
                                         CheckX.push_back(CheckX[k] + 1);
                                         CheckY.push_back(CheckY[k]);
                                         checked[CheckX[k] + 1][CheckY[k]] = true;
                                         needAdd = true;
                                 }
                                 if(CheckY[k] - 1 >= 0 && !checked[CheckX[k]][CheckY[k] -1 ] && board[CheckX[k]][CheckY[k] - 1] == 'O'){
                                         CheckX.push_back(CheckX[k]);
                                         CheckY.push_back(CheckY[k] - 1);
                                         checked[CheckX[k]][CheckY[k] -1 ] = true;
                                         needAdd = true;
                                 }
                                 if(CheckY[k] + 1 < board[0].size() && !checked[CheckX[k]][CheckY[k] + 1] && board[CheckX[k]][CheckY[k] + 1] == 'O'){
                                         CheckX.push_back(CheckX[k]);
                                         CheckY.push_back(CheckY[k]+1);
                                         checked[CheckX[k]][CheckY[k] + 1] = true;
                                         needAdd = true;
                                 }
                             }
                         }
                         bool notSurrounded = false;
                         for(int k = 0; k < CheckX.size(); k++){
                             if(CheckX[k] == 0 || CheckX[k] == board.size() - 1){
                                 notSurrounded = true;
                                 break;
                             }
                             if(CheckY[k] == 0 || CheckY[k] == board[0].size() - 1){
                                 notSurrounded = true;
                                 break;
                             }
                         }
                         if(!notSurrounded){
                             for(int k = 0; k < CheckX.size(); k++){
                                 board[CheckX[k]][CheckY[k]] = 'X';
                             }
                         }
                     }
                 }
             }
         }

    }
};
