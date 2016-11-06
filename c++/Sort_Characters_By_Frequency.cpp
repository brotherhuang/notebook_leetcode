/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class Solution {
public:
    static bool compare(pair<char, int> p1, pair<char, int> p2){
        return p1.second < p2.second;
    }
    string frequencySort(string s) {
        vector<pair<char, int>> charList;
        for(int i = 0; i < 256; i++){
            charList.push_back(pair<char,int>('\0' + i, 0));
        }
        for(auto c : s){
            charList[c - '\0'].second++;
        }
        sort(charList.begin(), charList.end(), compare);
        string res;
        for(int i = 255; i >=0; i--){
            if(charList[i].second == 0) return res;
            for(int j = 0; j < charList[i].second; j++) res.push_back(charList[i].first);
        }
        return res;
    }
};
