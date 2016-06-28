/* A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2. */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        int start = 0;
        int end = n - 1;
        int mid = 0;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if((mid == 0 || nums[mid] >= nums[mid - 1]) &&
               (mid == n - 1 || nums[mid] >= nums[mid + 1])) {
                    return mid;
            }else if(mid > 0 && nums[mid-1] > nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return mid;
    }
};
