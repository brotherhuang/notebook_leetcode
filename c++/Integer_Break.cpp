/* Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2. */

class Solution {
public:
    int integerBreak(int n) {
        int res = 0;
        for(int i = 2; i <=n; i++) {
            int base = n/i;
            int left = n - base*i;
            int currentmax = pow(base, i - left) * pow(base + 1, left);
            if(res < currentmax) {
                res = currentmax;
            }
        }
        return res;
    }
};
