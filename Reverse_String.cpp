/*Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

Subscribe to see which companies asked this question */
class Solution {
public:
    string reverseString(string s) {
        string res;
        for(int i = 0; i < s.size(); i++){
            res.push_back(s[s.size() - i - 1]);
        }
        return res;
    }
};
