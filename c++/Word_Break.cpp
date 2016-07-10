/* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". */

class Solution {
public:
    bool findBreak(string s, int pos, unordered_set<string> wordDict, vector<bool> &possible){
        if(pos == s.size()){
            return true;
        }
        for(int i = pos; i < s.size(); i++){
            string current = s.substr(pos, i - pos + 1);
            if(wordDict.count(current) != 0 && possible[i+1]){
                if(findBreak(s, i + 1,wordDict,possible)) return true;
                possible[i + 1] = false;
            }
        }
        return false;
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {
         vector<bool> possible(s.size() + 1, true);
         return findBreak(s, 0, wordDict,possible);
    }
};


class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
       vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j>=0; j--) {
                if(dp[j] && wordDict.count(s.substr(j,i-j+1))!=0) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
