/* Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
] */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       if(strs.size() == 0) return res;
       unordered_map<string, int> mp;
       for(int i = 0; i < strs.size(); i++){
           vector<int> wordMap(26,0);
           for(int j = 0; j < strs[i].size(); j++){
               wordMap[strs[i][j] - 'a']++;
           }
           string mapWord;
           for(int j = 0; j < wordMap.size(); j++){
               mapWord.push_back(wordMap[j] + 'a');
           }
           if(mp.find(mapWord) == mp.end()){
               mp[mapWord] = res.size();
               vector<string> newWord = {strs[i]};
               res.push_back(newWord);
           }
           else{
               res[mp[mapWord]].push_back(strs[i]);
           }
       }
       return res;
    }
};
