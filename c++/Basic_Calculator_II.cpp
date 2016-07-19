/* Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function. */
class Solution {
public:
    int calculate(string s) {
        int result = 0, inter_res = 0, num = 0;
        char op = '+';
        char ch;
        for (int pos = s.find_first_not_of(' '); pos < s.size(); pos = s.find_first_not_of(' ', pos)) {
            ch = s[pos];
            if (ch >= '0' && ch <= '9') {
                int num = ch - '0';
                while (++pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
                    num = num * 10 + s[pos] - '0';
                switch (op) {
                case '+':
                    inter_res += num;
                    break;
                case '-':
                    inter_res -= num;
                    break;
                case '*':
                    inter_res *= num;
                    break;
                case '/':
                    inter_res /= num;
                    break;
                }
            }
            else {
                if (ch == '+' || ch == '-') {
                    result += inter_res;
                    inter_res = 0;
                }
                op = s[pos++];
            }
        }
        return result + inter_res;
    }
};
