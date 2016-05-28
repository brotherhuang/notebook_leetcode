/* Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]  */
class Solution {
public:
    void getCombination(int target,  int start,vector<int> candidates, vector<int> &ress, vector<vector<int>> & res){
        if(target == 0){
            res.push_back(ress);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] <= target ){
            ress.push_back(candidates[i]);
            getCombination(target - candidates[i], i,candidates, ress, res);
            ress.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ress;
        sort(candidates.begin(),candidates.end());
        getCombination(target,0,candidates,ress,res);
        return res;
    }
};
