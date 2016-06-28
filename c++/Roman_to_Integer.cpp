/* Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999. */
class Solution {
public:
// I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和（1000）
    int char2num(char s){
        if(s == 'I'){
            return 1;
        }
        if(s == 'V'){
            return 5;
        }
        if(s == 'X'){
            return 10;
        }
        if(s == 'L'){
            return 50;
        }
        if(s == 'C'){
            return 100;
        }
        if(s == 'D'){
            return 500;
        }
        return 1000;
    }
    int romanToInt(string s) {
        int res = char2num(s[0]);
        int pernum = res;
        for(int i = 1; i < s.size();i++){
            int curnum = char2num(s[i]);
            if(curnum > pernum){
                res += curnum - 2*pernum;
            }
            else{
                res += curnum;
            }
            pernum = curnum;
        }
        return res;
    }
};
