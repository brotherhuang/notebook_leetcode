/* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
] */
class Solution {
public:
    void findSolution(int n, vector<int> pos, int row, vector<vector<string>>& res){
        if(pos.size() == n){
            string line(n,'.');
            vector<string> ress(n,line);
            for(int i = 0; i < pos.size(); i++){
                ress[i][pos[i]] = 'Q';
            }
            res.push_back(ress);
        }
        for(int i  = 0; i < n; i++){
            bool valid = true;
            for(int j = 0; j < pos.size(); j++){
                if(i == pos[j] || abs(i - pos[j]) == row - j){
                    valid = false;
                    break;
                }
            }
            if(valid){
                pos.push_back(i);
                findSolution(n,pos,row + 1, res);
                pos.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos;
        findSolution(n,pos,0,res);
        return res;
    }
};
