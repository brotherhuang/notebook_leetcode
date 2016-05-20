/*Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once. */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int maxVal = n;
        int minVal = 0;
        while(minVal <= maxVal){
            int middle = minVal + (maxVal -minVal)/2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= middle){
                    count ++;
                }
            }
            if(count <= middle){
                minVal = middle + 1;
            }
            else
            {
                maxVal = middle - 1;
            }
        }
        return minVal;
    }
};
