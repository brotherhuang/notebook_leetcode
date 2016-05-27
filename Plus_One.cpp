/*Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        vector<int> res;
        for(int i = 0; i < digits.size(); i++)
        {
            int current = digits[digits.size() - 1 - i] + add;
            res.push_back(current % 10);
            add = current /10;
        }
        if(add == 1)
        {
            res.push_back(add);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
