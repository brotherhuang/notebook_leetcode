/* Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/
class Solution {
public:
  int findLeftMost(vector<int>& nums, int target) {
      int start = 0, end = nums.size()-1;
      while(start<=end) {
          int mid = start + (end-start)/2;
          if(target <= nums[mid])
              end = mid-1;
          else
            start = mid+1;
      }
      if(start>=0 && start<nums.size() && nums[start]==target) return start;
      return -1;
  }
  int findRightMost(vector<int>& nums, int target) {
      int start = 0, end = nums.size()-1;
      while(start<=end) {
          int mid = start + (end-start)/2;
          if(target<nums[mid])
              end = mid-1;
          else
              start = mid+1;
      }
      if(end>=0 && end<nums.size() && nums[end]==target) return end;
      return -1;
  }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        range.push_back(findLeftMost(nums, target));
        range.push_back(findRightMost(nums, target));
        return range;
    }
};
