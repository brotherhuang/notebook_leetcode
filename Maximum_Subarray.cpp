/* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6. */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum < 0){
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            maxVal = max(maxVal, sum);
        }
        return maxVal;
    }
};
