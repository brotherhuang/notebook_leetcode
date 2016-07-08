/* Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024*/
class Solution {
public:
    int mod = 1337;
    int powerWithMod(int a, int b){
        int ans = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) ans = ans * a % mod;
            a = a * a %mod;
            b >>= 1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        int res = 1;
        for(int i = n - 1; i >= 0; i--){
            res = res * powerWithMod(a,b[i]) % mod;
            a = powerWithMod(a,10) % mod;
        }
        return res;
    }
};
