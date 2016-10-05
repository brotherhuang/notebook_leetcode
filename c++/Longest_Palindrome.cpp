/* 
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(52, 0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] - 'a' < 26 && s[i] - 'a' >= 0) count[s[i] - 'a']++;
            if(s[i] - 'A' < 26 && s[i] - 'A' >= 0)  count[26 + s[i] - 'A']++;
        }
        int total = 0;
        int maxOdd = 0;
        for(auto val : count){
            if(val % 2 == 0) total += val;
            else {
                maxOdd = max(maxOdd, val);
                total += val - 1;
            }
                
        }
        return maxOdd > 0 ? total + 1 : total;
    }
};