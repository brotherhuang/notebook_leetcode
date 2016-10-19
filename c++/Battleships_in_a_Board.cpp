/* Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return 0;
        int m = board[0].size();
        vector<vector<bool>> checked(n, vector<bool>(m,false));
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!checked[i][j]){
                    if(board[i][j] == '.') {
                        checked[i][j] = true;
                    }
                    else{
                        vector<pair<int,int>> xlist;
                        xlist.push_back(pair<int,int>(i,j));
                        bool xchanged = false;
                        bool ychanged = false;
                        while(xlist.size() > 0){
                            int currentX = xlist.back().first;
                            int currentY = xlist.back().second;
                            xlist.pop_back();
                            checked[currentX][currentY] = true;
                            if(currentX - 1 >= 0 && !checked[currentX - 1][currentY] && board[currentX - 1][currentY] == 'X' ) {
                                xlist.push_back(pair<int,int>(currentX - 1,currentY));
                                xchanged = true;
                            }
                            if(currentX + 1 < n && !checked[currentX + 1][currentY] && board[currentX + 1][currentY] == 'X') {
                                xlist.push_back(pair<int,int>(currentX + 1,currentY));
                                xchanged = true;
                            }
                            if(currentY - 1 >= 0 && !checked[currentX][currentY-1] && board[currentX][currentY-1] == 'X'){
                                xlist.push_back(pair<int,int>(currentX,currentY-1));
                                ychanged = true;
                            }
                            if(currentY + 1 < m && !checked[currentX][currentY+1] && board[currentX][currentY+1] == 'X'){
                                xlist.push_back(pair<int,int>(currentX,currentY+1));
                                ychanged = true;
                            }
                        }
                        if(!xchanged || !ychanged) res++;
                    }
                }
            }
        }
        return res;
    }
};
