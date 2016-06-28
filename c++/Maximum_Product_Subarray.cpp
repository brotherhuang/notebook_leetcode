/* Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res, currentMax, currentMin;
        res = nums[0];
        currentMax = nums[0];
        currentMin = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int temp = currentMax;
            currentMax = max(max(currentMax * nums[i], currentMin * nums[i]), nums[i]);
            currentMin = min(min(temp * nums[i], currentMin * nums[i]), nums[i]);
            res = max(res, currentMax);
        }
        return res;
    }
};
