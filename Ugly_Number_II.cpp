/* Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5). */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2,3,5};
        int k = primes.size();
        vector<int> pos(k, 0);
        vector<int> ugly(n, INT_MAX);
        ugly[0] = 1;

        for(int i = 1; i< n; i++)
        {
            for(int j = 0; j < k; j++)
                ugly[i] = (ugly[i] < ugly[pos[j]] * primes[j]) ? ugly[i] : (ugly[pos[j]] * primes[j]);

            for(int j = 0; j < k; j++)
                if(ugly[i] == ugly[pos[j]] * primes[j]) pos[j]++;
        }
        return ugly[n - 1];
    }
};
