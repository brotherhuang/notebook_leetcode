/* Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion? */
class Solution {
public:
    bool isPowerOfThree(int n) {
         return n != 0 && 3486784401u % n == 0;
    }
};
