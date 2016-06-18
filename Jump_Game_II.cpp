/* Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) */
class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+nums[i]);
        }

        return ret;
    }
};
