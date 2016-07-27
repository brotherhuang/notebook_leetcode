/* Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. */

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return 0;
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]].push_back(i);
            }
            else mp[s[i]] = {i};
        }
        for(int i = 0; i < t.size(); i++){
            if(mp.find(t[i]) == mp.end()){
                return 0;
            }
        }
        vector<int> preIndex = mp[t.back()];
        vector<int> prePath(preIndex.size(),1);
        int total = preIndex.size();
        for(int i = t.size() - 2; i >=0; i--){
            vector<int> curIndex = mp[t[i]];
            vector<int> curPath(curIndex.size(),0);
            total = 0;
            for(int j = 0; j < curIndex.size(); j++){
                for(int k = 0; k <preIndex.size(); k++){
                    if(curIndex[j] < preIndex[k]) {
                        curPath[j] += prePath[k];
                        total += prePath[k];
                    }
                }
            }
            if(total == 0) return 0;
            preIndex = curIndex;
            prePath = curPath;
        }
        return total;
    }
};

/* ------------------------------------------------*/


class Solution {
public:
    void findDistinct(string t, int pos, unordered_map<char, vector<int>> mp, int lastPos, int &totalPath){
        if(pos == t.size()){
            totalPath++;
            return;
        }
        int currentChar = t[pos];
        if(mp.find(currentChar) != mp.end()){
            for(int i = 0; i < mp[currentChar].size(); i++){
                if(mp[currentChar][i] > lastPos) {
                    findDistinct(t, pos + 1, mp, mp[currentChar][i], totalPath);
                }
            }
        }
    }
    int numDistinct(string s, string t) {
        if(s.size() == 0) return 0;
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]].push_back(i);
            }
            else mp[s[i]] = {i};
        }
        int totalPath = 0;
        findDistinct(t, 0, mp, -1, totalPath);
        return totalPath;

    }
};
