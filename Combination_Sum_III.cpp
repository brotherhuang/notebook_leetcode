/* Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]] */
class Solution {
public:
    void getCombination(int target, int k, vector<int> &res, vector<vector<int>> &resList){
        if(target < 0){
            return;
        }
        if(target == 0 && res.size() == k){
            resList.push_back(res);
        }
        else{
            for(int j = 1; j <= 9; j++){
                if(res.size() == 0 || j > res.back()){
                    res.push_back(j);
                    getCombination(target - j, k, res, resList);
                    res.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        vector<vector<int>> resList;
        getCombination(n,k,res,resList);
        return resList;
    }
};
