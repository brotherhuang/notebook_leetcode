/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        if(n <= 1) return false;
        for(int i = 1; i <= n / 2; i++){
            if( n % i == 0){
                int repeat = n / i;
                string pattern = str.substr(0, i);
                bool find = true;
                for(int j = 1; j < repeat; j++){
                    if(str.substr(j * i, i).compare(pattern) != 0){
                        find = false;
                        break;
                    }
                }
                if(find) return true;
            }
        }
        return false;
    }
};
