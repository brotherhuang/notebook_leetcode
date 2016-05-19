/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB */
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0){
            res.push_back('A' + (n - 1)%26);
            n = (n - 1)/26;
        }
        for(int i = 0; i < res.size()/2; i++){
            swap(res[i], res[res.size() - i - 1]);
        }
        return res;
    }
};
