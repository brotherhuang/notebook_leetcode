/* Implement pow(x, n). */
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == INT_MIN && x > 1) return 0.0;
        int sign = 1;
        if(n < 0) {
            sign = -1;
            n = -n;
        }
        double res = myPow(x,n/2);
        res*= res;
        if(n%2 == 1) res*= x;
        if(sign == -1) return 1.0/res;
        return res;
    }
};
