/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Could you do it without any loop/recursion in O(1) runtime? */

class Solution {
public:
    int addDigits(int num) {
        while(num >= 10)
        {
            int res = 0;
            while(num > 0)
            {
                res += num % 10;
                num /= 10;
            }
            num = res;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
      return (num - 1) % 9 + 1;
    }
};