/* Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".*/
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        vector<string> strList;
        vector<int> repeadSize;
        string current = "";
        int nums = 0;
        string words;
        for(int i = 0; i < s.size(); i++){
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9) nums = nums * 10 + s[i] - '0';
            else if(s[i] == '['){
                repeadSize.push_back(nums);
                nums = 0;
                strList.push_back(words);
                words = "";
            }
            else if(s[i] == ']'){
                int copyTime = repeadSize.back();
                repeadSize.pop_back();
                for(int k = 0; k < copyTime; k++){
                    strList.back() += words;
                }
                words = strList.back();
                strList.pop_back();
            }
            else {
                words.push_back(s[i]);
            }
        }
        return strList.size() == 0 ? words : strList.back();
    }
};
