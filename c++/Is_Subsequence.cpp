/* Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false. */
class Solution {
public:
    bool isSubsequence(string s, string t) {
       int pos = 0;
       for(int i = 0; i < s.length(); ++i) {
            bool is_match = false;
            for(int j = pos; j < t.length(); ++j){
                if(t[j] == s[i]){
                    pos = j + 1;
                    is_match = true;
                    break;
                }
            }
            if(!is_match) return false;
        }
        return true;
    }
};