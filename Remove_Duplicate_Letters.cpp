/* Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb" */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charList(26,0);
        for (const auto& c : s) {
            charList[c - 'a']++;
        }
        vector<bool> usedChar(26,false);
        string res;
        for (const auto& c : s) {
            if (!usedChar[c - 'a']) {
                while (!res.empty() && res.back() > c && charList[res.back() - 'a']) {
                    usedChar[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                usedChar[c - 'a'] = true;
            }
            charList[c - 'a']--;
        }
        return res;
    }
};
