/*
A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.
*/
class Solution {
public:
    int strongPasswordChecker(string s) {
        int deleteTarget = max(0, (int)s.length() - 20), addTarget = max(0, 6 - (int)s.length());
        int toDelete = 0, toAdd = 0, toReplace = 0, needUpper = 1, needLower = 1, needDigit = 1;

        for (int l = 0, r = 0; r < s.length(); r++) {
            if (isupper(s[r])) { needUpper = 0; }
            if (islower(s[r])) { needLower = 0; }
            if (isdigit(s[r])) { needDigit = 0; }

            if (r - l == 2) {
                if (s[l] == s[l + 1] && s[l + 1] == s[r]) {
                    if (toAdd < addTarget) { toAdd++, l = r; }
                    else { toReplace++, l = r + 1; }
                } else { l++; }
            }
        }
        if (s.length() <= 20) { return max(addTarget + toReplace, needUpper + needLower + needDigit); }

        toReplace = 0;
        vector<unordered_map<int, int>> lenCnts(3);
        for (int l = 0, r = 0, len; r <= s.length(); r++) {
            if (r == s.length() || s[l] != s[r]) {
                if ((len = r - l) > 2) { lenCnts[len % 3][len]++; }
                l = r;
            }
        }

        for (int i = 0, numLetters, dec; i < 3; i++) {
            for (auto it = lenCnts[i].begin(); it != lenCnts[i].end(); it++) {
                if (i < 2) {
                    numLetters = i + 1, dec = min(it->second, (deleteTarget - toDelete) / numLetters);
                    toDelete += dec * numLetters, it->second -= dec;
                    if (it->first - numLetters > 2) { lenCnts[2][it->first - numLetters] += dec; }
                }
                toReplace += (it->second) * ((it->first) / 3);
            }
        }

        int dec = (deleteTarget - toDelete) / 3;
        toReplace -= dec, toDelete -= dec * 3;
        return deleteTarget + max(toReplace, needUpper + needLower + needDigit);
    }
};
