/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        vector<int> sums(nums.size(), 0);
        sums.back() = nums.back();
        for(int i = nums.size() - 2; i >=0; i--)  sums[i] = sums[i + 1] + nums[i];
        int res = 0;
        helper(nums, sums, S, 0,res);
        return res;
    }
    void helper(vector<int>& nums, vector<int>& sums, int target, int pos, int& res){
        if(pos == nums.size()){
            if(target == 0) res++;
            return;
        }

        if (sums[pos] < abs(target)) return;

        helper(nums, sums, target + nums[pos], pos + 1,res);
        helper(nums, sums, target - nums[pos], pos + 1,res);
    }

};
