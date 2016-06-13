/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int start = s.size() - 1;
        while(s[start] == ' '){
            start--;
        }
        while(start >=0 && s[start]!= ' '){
            res++;
            start--;
        }
        return res;
    }
};
