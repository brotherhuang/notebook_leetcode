/* Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false. */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
         vector<string> words;
         int start = 0;
         for(int i = 0; i < str.size(); i++){
             if(str[i] == ' '){
                 words.push_back(str.substr(start, i - start));
                 start = i + 1;
             }
         }
         words.push_back(str.substr(start, str.size() - start + 1));
         if(words.size() != pattern.size()) {
             return false;
         }
         for(int i = 0; i < pattern.size(); i++){
             for(int j = i + 1; j < pattern.size(); j++){
                 if(pattern[j] == pattern[i] && words[i] != words[j]){
                     return false;
                 }
                 if(pattern[j] != pattern[i] && words[i] == words[j]){
                     return false;
                 }                 
             }
         }
         return true;
    }
};