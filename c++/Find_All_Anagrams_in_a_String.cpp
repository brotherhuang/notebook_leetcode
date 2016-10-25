/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
       if(s.size() < p.size()) return res;
       vector<int> diff(26,0);
       for(int i = 0; i < p.size(); i++){
           diff[p[i] - 'a']++;
       }
       for(int i = 0; i <= s.size() - p.size(); i++){
           if(i == 0){
               for(int j = 0; j < p.size(); j++){
                   diff[s[i + j] - 'a']--;
               }
           }
           else {
               diff[s[i - 1] - 'a']++;
               diff[s[i + p.size() - 1] - 'a']--;
           }
           bool same = true;
           for(int j = 0; j < 26; j++){
               if(diff[j] != 0) same =false;
           }
           if(same) res.push_back(i);
       }
       return res;
    }
}
