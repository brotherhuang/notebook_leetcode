/* Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets. */
class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.size() != t.size()) {return false;}
         vector<int> charcount(26,0);
         for(int i =0; i < s.size(); i++){
             charcount[s[i] - 'a']++;
             charcount[t[i] - 'a']--;
         }
         for(int i =0; i < charcount.size(); i++) {
             if(charcount[i]!= 0){
                 return false;
             }
         }
         return true;
    }
};
