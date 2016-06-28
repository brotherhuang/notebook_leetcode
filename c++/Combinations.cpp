/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/
class Solution {
public:
    void getCombine(int n, int start, int k, vector<int> &rese, vector<vector<int>>& res){
        if(rese.size() == k){
            res.push_back(rese);
            return;
        }
        for(int i = start; i < n; i++){
            rese.push_back(i+1);
            getCombine(n,i+1,k,rese,res);
            rese.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> rese;
        getCombine(n,0,k,rese,res);
        return res;
    }
};
