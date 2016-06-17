/* Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Subscribe to see which companies asked this question */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]) return true;
            if(nums[mid] > nums[start]){
                if(nums[start]<=target && target<= nums[mid]) end = mid - 1;
                else start = mid + 1;
            }
            else if (nums[mid] < nums[start]){
                if(nums[mid]>=target || target>= nums[start]) end = mid -1 ;
                else start = mid + 1;
            }
            else start++;
        }
        return false;
    }
};
