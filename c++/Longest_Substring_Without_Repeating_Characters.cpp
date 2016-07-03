/* Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring. */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxLen = 0;
        int lastIndex = -1;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] > lastIndex){
                lastIndex = mp[s[i]];
            }
            maxLen = max(maxLen, i - lastIndex);
            mp[s[i]] = i;
        }
        return maxLen;
    }
};

/******************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxLen = 0;
        int currentLen = 0;
        int lastIndex = -1;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] > lastIndex){
                lastIndex = mp[s[i]];
                maxLen = max(maxLen, currentLen);
                currentLen = i - mp[s[i]];
                mp[s[i]] = i;
            }
            else{
                mp[s[i]] = i;
                currentLen++;
            }
        }
        return max(maxLen, currentLen);
    }
};
