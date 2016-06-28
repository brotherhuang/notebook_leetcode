/* Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]  */
class Solution {
public:
    void comSum(vector<int> candidates, int start, int target, vector<vector<int>>& res, vector<int> rs){
        if(target == 0 && rs.size() != 0 ){
            res.push_back(rs);
            return;
        }
        int pre = -1;
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i]!=pre && candidates[i] <= target){
                rs.push_back(candidates[i]);
                comSum(candidates, i + 1, target -candidates[i] , res, rs);
                pre = candidates[i];
                rs.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> rs;
        comSum(candidates,0,target,res,rs);
        return res;
    }
};
