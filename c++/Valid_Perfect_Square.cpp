/* Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0 ) return false;
        long long start = 0;
        long long end = num/2 + 1;
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(mid * mid == num) return true;
            else if(mid * mid < num) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};
