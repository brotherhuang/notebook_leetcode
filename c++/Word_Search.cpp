/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false. */
class Solution {
public:
    bool dfs(int i, int j, int pos, string word, vector<vector<char>>& board, vector<vector<bool>>& mask){
        if(pos == word.size() - 1) return true;
        vector<pair<int,int>> candidate;
        if(i - 1 >= 0 && !mask[i-1][j]){
            candidate.push_back(pair<int,int> (i-1,j));
        }
        if(i + 1 < board.size()&& !mask[i+1][j]){
            candidate.push_back(pair<int,int> (i+1,j));
        }
        if(j - 1 >= 0&& !mask[i][j-1]){
            candidate.push_back(pair<int,int> (i,j - 1));
        }
        if(j+ 1 < board[0].size()&& !mask[i][j+1]){
            candidate.push_back(pair<int,int> (i,j + 1));
        }
        for(int i = 0; i < candidate.size(); i++){
            if(board[candidate[i].first][candidate[i].second] == word[pos + 1]){
                mask[candidate[i].first][candidate[i].second] = true;
                if(dfs(candidate[i].first, candidate[i].second, pos + 1, word, board, mask)) return true;
                mask[candidate[i].first][candidate[i].second] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) {
            return false;
        }
        vector<vector<bool>> mask(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                   mask[i][j] = true;
                   if(dfs(i, j, 0, word, board, mask)) {
                       return true;
                   }
                   mask[i][j] = false;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool search(vector<vector<char>>& board, int  i, int j, string word, vector<vector<bool>>& mask) {
        if(word.size() == 0) {
            return true;
        }
        else {
        if(i > 0 && board[i - 1][j] == word[0] &&  mask[i - 1][j] == false) {
            mask[i - 1][j] = true;
            if(search(board, i - 1, j, word.substr(1), mask)) {
                return true;
            }
            mask[i - 1][j] = false;
        }
        if(i < board.size() - 1 && board[i + 1][j] == word[0] &&  mask[i + 1][j] == false) {
            mask[i + 1][j] = true;
            if(search(board, i + 1, j, word.substr(1), mask)) {
                return true;
            }
            mask[i + 1][j] = false;
        }
        if(j > 0 && board[i][j - 1] == word[0] &&  mask[i][j - 1] == false) {
            mask[i][j - 1] = true;
            if(search(board, i, j - 1, word.substr(1), mask)) {
                return true;
            }
            mask[i][j - 1] = false;
        }
        if(j < board[0].size() - 1 && board[i][j + 1] == word[0] &&  mask[i][j + 1] == false) {
            mask[i][j + 1] = true;
            if(search(board, i, j + 1, word.substr(1), mask)) {
                return true;
            }
            mask[i][j + 1] = false;
        }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) {
            return false;
        }
        vector<vector<bool>> mask(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                   mask[i][j] = true;
                   if(search(board, i, j, word.substr(1), mask)) {
                       return true;
                   }
                   mask[i][j] = false;
                }
            }
        }
        return false;
    }
};
