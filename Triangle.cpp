/* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> res = triangle;
        for(int level = res.size() - 2; level >= 0; level--){
            for(int j = 0; j < res[level].size(); j++){
                res[level][j] = min(res[level][j] + res[level + 1][j], res[level][j] + res[level + 1][j + 1]);
            }
        }
        return res.front().front();
    }
};
