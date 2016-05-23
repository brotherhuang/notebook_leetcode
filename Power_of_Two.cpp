/* Given an integer, write a function to determine if it is a power of two. */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int res;
        while(n > 1){
            if(n % 2 == 0){
                n /= 2;
            }
            else{
                return false;
            }
        }
        if(n == 1){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return ( (n>0) && (n & (n-1))==0 ) || (n==1);
    }
};
