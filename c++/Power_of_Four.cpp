/*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        while(num % 4 == 0) num /= 4;
        if(num == 1) return true;
        return false;
    }
};
