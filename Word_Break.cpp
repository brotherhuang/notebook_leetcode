/* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". */
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
