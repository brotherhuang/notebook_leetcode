/* The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2 */
class Solution {
public:
    unsigned int binary2gray(unsigned int bi){
        return (bi>>1)^bi;
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        for (unsigned int i=0;i<pow(2,n);i++){
            res.push_back(binary2gray(i));
        }
        return res;
    }
};
