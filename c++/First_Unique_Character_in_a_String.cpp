/*Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2. */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26,0);
        for(int i = 0; i < s.size(); i++){
            mp[s[i] - 'a' ] ++;
        }
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i] - 'a' ] == 1) return i;
        }
        return -1;
    }
};
