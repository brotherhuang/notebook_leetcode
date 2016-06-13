/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. */
class Solution {
public:
    bool isPalindrome(string s) {
         int begin = 0;
         int end = s.size() - 1;
         while(begin < end){
             while(begin < s.size() && !isalnum(s[begin])){
                 begin++;
             }
             while(end >= 0 && !isalnum(s[end])){
                 end--;
             }
             if(begin>=end) return true;
             if(tolower(s[begin++])!=tolower(s[end--])) return false;
         }
         return true;
    }
};