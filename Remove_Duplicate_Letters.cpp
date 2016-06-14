/* Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb" */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charlist(26,0);
        for (const auto& c : s) {
            charlist[c - 'a']++;
        }
        unordered_set<char> in_stack;
        string res;
        for (const auto& c : s) {
            if (!in_stack.count(c)) {
                while (!res.empty() && res.back() > c && charlist[res.back() - 'a']) {
                    in_stack.erase(res.back());
                    res.pop_back();
                }
                res.push_back(c);
                in_stack.emplace(c);
            }
            charlist[c - 'a']--;
        }
        return res;
    }
};
