/* Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ] */

  class Solution {
  public:
      vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
          unordered_set<string> usedWord;
          usedWord.insert(beginWord);
          vector<vector<string>> res;
          vector<string> currentLevelWord;
          currentLevelWord.push_back(beginWord);
          res.push_back(currentLevelWord);
          while(res.size() > 0){
              vector<vector<string>> resNew;
              bool haveEnd = false;
              for(int i = 0; i < res.size(); i++){
                  string currentWord = res[i].back();
                  for(int j = 0; j < currentWord.size(); j++){
                      string diffWord = currentWord;
                      for(int k = 0; k < 26; k++){
                          diffWord[j] = 'a' + k;
                          if(wordList.find(diffWord) != wordList.end() && usedWord.find(diffWord) == usedWord.end()){
                             vector<string> newlist = res[i];
                             newlist.push_back(diffWord);
                             if(diffWord.compare(endWord) == 0) haveEnd = true;
                             resNew.push_back(newlist);
                          }
                      }
                  }
              }

              if(haveEnd){
                  res.clear();
                  for(int i = 0 ; i < resNew.size(); i++){
                      if(resNew[i].back().compare(endWord) == 0) res.push_back(resNew[i]);
                  }
                  return res;
              }
              res = resNew;
              for(int i = 0 ; i < resNew.size(); i++){
                      usedWord.insert(resNew[i].back());
                  }
          }
          return res;
      }
  };
