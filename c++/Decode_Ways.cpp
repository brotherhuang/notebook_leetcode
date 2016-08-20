/* A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. */
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        vector<int> res(s.size() + 1, 0);
        if(s.back() != '0') res[s.size() - 1] = 1;
        if(s.size() >= 2 && stoi(s.substr(s.size() - 2, 2)) <= 26 && s[s.size() - 2] != '0') res.back() = 1;
        for(int i = s.size() - 2 ; i >=0; i--){
            if(s[i] != '0') {
                res[i] += res[i+1];
            }
            if(s[i] != '0' && stoi(s.substr(i, 2)) <= 26){
                res[i] += res[i+2];
            }
        }
        return res[0];
    }
};
