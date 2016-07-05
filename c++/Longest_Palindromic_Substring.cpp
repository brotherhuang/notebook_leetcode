/* Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring. */
class Solution {
public:
    string findPalindrome(string s, int start, int end){
        while(s[start] == s[end] && start >= 0 && end < s.size()){
            start--;
            end++;
        }
        return s.substr(start + 1, end - start - 1);
    }
    string longestPalindrome(string s) {
        string res("");
        for(int i = 0; i < s.size(); i++){
            string s1 = findPalindrome(s, i, i);
            string s2 = findPalindrome(s, i, i +1);
            if(s1.size() > res.size()) res = s1;
            if(s2.size() > res.size()) res = s2;
        }
        return res;
    }
};
