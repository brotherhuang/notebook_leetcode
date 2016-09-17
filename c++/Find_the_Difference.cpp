/* Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.
Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> mp(26,0);
        for(auto c : s){
            mp[c - 'a']++;
        }
        for(auto c : t){
            mp[c - 'a']--;
        }
        for(int i = 0; i < mp.size(); i++){
            if(mp[i] == -1) return 'a' + i;
        }
        return 'a';
    }
};
