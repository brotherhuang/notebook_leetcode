/* Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"]. */

class Solution {
public:
    bool checkWord(vector<vector<bool>> checked,vector<vector<char>>board, string word, int checkLevel, int perviousX, int perviousY){
         if(checkLevel == word.size()) return true;
         checked[perviousX][perviousY] = true;
         if(perviousX > 0 && board[perviousX - 1][perviousY] == word[checkLevel]) {
             if(checkWord(checked,board, word, checkLevel + 1, perviousX - 1, perviousY)) return true;
         }
         if(perviousX < board.size() - 1 && board[perviousX + 1][perviousY] == word[checkLevel]) {
             if(checkWord(checked,board, word, checkLevel + 1, perviousX + 1, perviousY)) return true;
         }
         if(perviousY > 0 && board[perviousX][perviousY - 1] == word[checkLevel]) {
             if(checkWord(checked,board, word, checkLevel + 1, perviousX, perviousY - 1)) return true;
         }
         if(perviousY < board[0].size() - 1 && board[perviousX][perviousY + 1] == word[checkLevel]) {
             if(checkWord(checked,board, word, checkLevel + 1, perviousX, perviousY + 1)) return true;
         }
         return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        vector<bool> isContain(words.size(),false);
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < words.size(); i++){
            string currentWord = words[i];
            for(int x = 0; x < n; x++){
                for(int y = 0; y < m; y++){
                    if(!isContain[i] && board[x][y] == currentWord[0]){
                        vector<vector<bool>> checked(n,vector<bool>(m,false));
                        checked[x][y] = true;
                            if(checkWord(checked,board,currentWord,1,x,y)) { isContain[i] = true; res.push_back(currentWord);}
                            }
                        }
                    }
                }
        return res;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        vector<bool> isContain(words.size(),false);
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < words.size(); i++){
            string currentWord = words[i];
            for(int x = 0; x < n; x++){
                for(int y = 0; y < m; y++){
                    if(!isContain[i] && board[x][y] == currentWord[0]){
                        int totalComb = pow(4,currentWord.size() - 1);
                        for(int k = 0; k < totalComb; k++){
                            if(!isContain[i]) {
                                vector<vector<bool>> checked(n,vector<bool>(m,false));
                                int currentX = x;
                                int currentY = y;
                                checked[currentX][currentY] = true;
                                bool validPath = true;
                                int currentProd = totalComb / 4;
                                int currentComb = k;
                                int currentLevel = 1;
                                while(validPath && currentLevel < currentWord.size()){
                                    int nextPos = currentComb / currentProd;
                                    currentComb = currentComb % currentProd;
                                    currentProd /= 4;
                                    if(nextPos == 0) {currentX--;}
                                    if(nextPos == 1) {currentX++;}
                                    if(nextPos == 2) {currentY--;}
                                    if(nextPos == 3) {currentY++;}
                                    if(currentX >= 0 && currentX < n && currentY >= 0 && currentY < m &&
                                       !checked[currentX][currentY] && board[currentX][currentY] == currentWord[currentLevel]){
                                           currentLevel ++;
                                           checked[currentX][currentY] = true;
                                       }
                                    else validPath = false;
                                }
                               if(currentLevel == currentWord.size()) { isContain[i] = true; res.push_back(currentWord);}
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
