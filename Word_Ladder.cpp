/* Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> usedWord;
        usedWord.insert(beginWord);
        int length = 1;
        vector<string> currentLevelWord;
        currentLevelWord.push_back(beginWord);
        while(currentLevelWord.size() > 0){
            vector<string> nextLevelWord;
            for(int i = 0; i < currentLevelWord.size(); i++){
                string currentWord = currentLevelWord[i];
                for(int j = 0; j < currentLevelWord[i].size(); j++){
                    string diffWord = currentWord;
                    for(int k = 0; k < 26; k++){
                        diffWord[j] = 'a' + k;
                        if(wordList.find(diffWord) != wordList.end() && usedWord.find(diffWord) == usedWord.end()){
                            nextLevelWord.push_back(diffWord);
                            usedWord.insert(diffWord);
                        }
                    }
                }
            }
            for(int  i = 0; i < nextLevelWord.size(); i++){
                if(nextLevelWord[i] == endWord){
                    return length + 1;
                }
            }
            currentLevelWord = nextLevelWord;
            length++;
        }
        return 0;
    }
};
