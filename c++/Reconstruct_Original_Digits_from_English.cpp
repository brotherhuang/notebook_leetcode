/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/
class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26,0);
        for(auto c : s){
            count[c - 'a']++;
        }
        // zero one two three four five six seven eight nine
        vector<int> digitCount(10,0);
        vector<string> checkOrder = {"zero", "six", "seven", "five", "eight", "four", "two", "three", "nine", "one"};
        vector<int> checkDigit = {0, 6, 7, 5, 8, 4, 2, 3, 9, 1};
        vector<char> checkChar = {'z', 'x', 's', 'v', 'g', 'u', 'w', 'r','i','o'};
        for(int i = 0; i < checkChar.size(); i++){
            while(count[checkChar[i] - 'a'] > 0){
                digitCount[checkDigit[i]]++;
                for(auto c : checkOrder[i]) count[c - 'a']--;
            }
        }
        string res;
        for(int i = 0; i < digitCount.size(); i++){
            for(int t = 0; t < digitCount[i]; t++) res += to_string(i);
        }
        return res;
    }
};
