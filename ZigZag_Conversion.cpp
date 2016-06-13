/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> res(numRows);
        int current = 0;
        int order = 1;
        for(int i = 0; i < s.size(); i++){
            res[current].push_back(s[i]);
            if(current == numRows - 1){
                order = -1;
            }
            if(current == 0){
                order = 1;
            }
            current += order;
        }
        string singleRes;
        for(string ss : res){
            singleRes = singleRes + ss;
        }
        return singleRes;
    }
};