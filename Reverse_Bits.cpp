/* Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000). */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> res;
        while(n >=2)
        {
            res.push_back(n%2);
            n /= 2;
        }
        res.push_back(n);
        for(int i = 0; i < 32 - res.size(); i++)
        {
            res.push_back(0);
        }
        uint32_t reverse = 0;
        for(int i = 0; i < res.size(); i++)
        {
            reverse += res[i] * pow(2, 31 - i);
        }
        return reverse;
    }
};
