/* Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1]. */
class Solution {
public:
    int getCombine(int n, int k){
        long res = n;
        if(k == 0){
            return 1;
        }
        for(int i = 2; i <= k; ++i){
            res *=  (n -i + 1);
            res /= i;
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i = 0; i <= rowIndex; i++){
            if(i > rowIndex - i){
                res.push_back(res[rowIndex - i]);
            }
            else  res.push_back(getCombine(rowIndex,i));
        }
        return res;
    }
};
