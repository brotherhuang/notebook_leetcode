/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
Subscribe to see which companies a */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return ;
        int checkPos = n - 2 ;
        while(checkPos >= 0 && nums[checkPos] >= nums[checkPos + 1]) checkPos--;
        if(checkPos < 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int swapPos = checkPos + 1;
        while(swapPos < n && nums[swapPos] > nums[checkPos]) swapPos++;
        swapPos--;
        swap(nums[swapPos],nums[checkPos]);
        sort(nums.begin() + checkPos + 1, nums.end());
    }
};
