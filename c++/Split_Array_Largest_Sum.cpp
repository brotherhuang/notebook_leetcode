/* Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.

Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(m == 1) {
            int sum = 0;
            for(auto num : nums) sum += num;
            return sum;
        }
        if(m >= nums.size()){
            int maxNum = 0;
            for(auto num : nums) maxNum = max(maxNum, num);
            return maxNum;
        }
        int maxNum = INT_MAX;
        int subsum = 0;
        for(int i = 0; i < nums.size(); i++){
            subsum += nums[i];
            vector<int> subarray(nums.begin() + i + 1, nums.end());
            maxNum = min(maxNum, max(subsum,splitArray(subarray, m-1)));
        }
        return maxNum;
    }
};
