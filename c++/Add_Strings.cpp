/* Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int minLen = min(num1.size(), num2.size());
        string res;
        for(int i = 0; i < minLen; i++){
            int current = num1[num1.size() - 1 - i] - '0' + num2[num2.size() -1 - i] - '0' + carry;
            res = to_string(current % 10) + res;
            carry = current / 10;
        }
        for(int i = minLen; i < num1.size(); i++){
            int current = num1[num1.size() - 1 - i] - '0' + carry;
            res = to_string(current % 10) + res;
            carry = current / 10;
        }
        for(int i = minLen; i < num2.size(); i++){
            int current = num2[num2.size() - 1 - i] - '0' + carry;
            res = to_string(current % 10) + res;
            carry = current / 10;
        }
        if(carry == 1) res = "1" + res;
        return res;
    }
};
