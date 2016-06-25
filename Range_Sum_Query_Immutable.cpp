/* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3 */
class NumArray {
public:
    vector<int> accumSum;
    NumArray(vector<int> &nums) {
        accumSum.resize(nums.size());
        int accume = 0;
        for(int i = 0; i < nums.size(); i++){
            accume += nums[i];
            accumSum[i] = accume;
        }
    }

    int sumRange(int i, int j) {
        if(i >= accumSum.size() || j >= accumSum.size()) return 0;
        if(i == 0) return accumSum[j];
        return accumSum[j] - accumSum[i - 1];
    }
};
