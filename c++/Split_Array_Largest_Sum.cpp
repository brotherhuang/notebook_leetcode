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
    bool validCut(int target,  vector<int> nums, int m){
        int cut = 1;
        int sum = 0;
        for(auto num : nums){
            sum += num;
            if(sum > target){
                sum = num;
                cut++;
                if(cut > m) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int minMax = -1;
        int sum = 0;
        for(auto num : nums){
            minMax = max(minMax, num);
            sum += num;
        }
        if(m == 1) return sum;
        if(m >= nums.size()) return minMax;
        while(minMax <= sum){
            int mid = minMax + (sum - minMax)/2;
            if(validCut(mid, nums, m)) sum = mid - 1;
            else minMax = mid + 1;
        }
        return minMax;
    }
};
