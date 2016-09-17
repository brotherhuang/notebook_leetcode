/* Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> p(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && t[i] != t[j]) j = p[j - 1];
            p[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - p[t.size() - 1]) + s;
    }
};
