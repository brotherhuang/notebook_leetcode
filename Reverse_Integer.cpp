/* Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 */
class Solution {
public:
    int reverse(int x) {
        int  res = 0;
        while (x!=0){
            if (res > INT_MAX/10 || res < INT_MIN/10){
                return 0;
            }
            res = res*10+ x%10;
            x= x/10;
        }
        return res;
    }
};
