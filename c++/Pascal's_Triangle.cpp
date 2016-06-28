/* Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
] */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0){
            return res;
        }
        vector<int> row0 = {1};
        res.push_back(row0);
        for(int i = 1; i < numRows; i++){
            vector<int> resi(i+1,1);
            for(int j = 1; j < i; j++){
                resi[j] = res.back()[j - 1] + res.back()[j];
            }
            res.push_back(resi);
        }
        return res;
    }
};
