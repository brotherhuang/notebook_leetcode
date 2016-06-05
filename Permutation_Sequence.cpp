/* The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive. */
class Solution {
public:
    string getPermutation(int n, int k) {
     string ret;
        vector<int> factorial(n,1);
        vector<char> num(n,1);

        for(int i=1; i<n; i++)
            factorial[i] = factorial[i-1]*i;

        for(int i=0; i<n; i++)
            num[i] = (i+1)+'0';

        k--;
        for(int i=n; i>=1; i--) {
            int j = k/factorial[i-1];
            k %= factorial[i-1];
            ret.push_back(num[j]);
            num.erase(num.begin()+j);
        }
        return ret;
    }
};
