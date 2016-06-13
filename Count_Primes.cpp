/* Description:

Count the number of prime numbers less than a non-negative number, n. */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n,true);
        int i = 2;
        while (i * i < n){
            for (int j = 2; j*i < n; j++){
                num[j*i] = false;
            }
             
            i++;
             
            while (num[i] == false && i*i < n){
                i++;
            }
        }
        int res=0;
        for (int i=2;i<n;i++){
            if (num[i] == true){
                res ++;
            }
        }
        return res;
    }
};