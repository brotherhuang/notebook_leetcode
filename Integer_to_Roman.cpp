/* Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.*/
class Solution {
public:
    string intToRoman(int num) {
        char roman[7] = {'I','V','X','L','C','D','M'};
        string res;
        int base = 1000;
        int index = 6;
        while(base > 0){
            int digit = num / base;
            if(digit <= 3){
                res.append(digit, roman[index]);
            }
            else if(digit == 4){
                res.append(1, roman[index]);
                res.append(1, roman[index + 1]);
            }
            else if(digit == 5){
                res.append(1, roman[index + 1]);
            }
            else if(digit <= 8){
                res.append(1, roman[index + 1]);
                res.append(digit - 5, roman[index]);
            }
            else{
                res.append(1, roman[index]);
                res.append(1, roman[index + 2]);
            }
            num = num % base;
            base = base / 10;
            index -= 2;
        }
        return res;
    }
};
