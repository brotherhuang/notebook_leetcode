/* Implement int sqrt(int x).

Compute and return the square root of x.*/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x < 4) return 1;
        int start = 0;
        int end= x/2<std::sqrt(INT_MAX)? x/2+1:std::sqrt(INT_MAX);
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid * mid == x) return mid;
            else if(mid * mid < x) start = mid + 1;
            else end = mid - 1;
        }
        return (start+end)/2;
    }
};
