/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
class Solution {
public:
    string reverseWords(string s) {
        string res;
        string current;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                res = res + current + " ";
                current = "";
            }
            else current = s.substr(i,1) + current;
            if(i == s.size() - 1) res = res + current;
        }
        return res;
    }
};