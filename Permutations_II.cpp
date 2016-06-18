/* Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
] */
class Solution {
public:
    bool nextPermutation(vector<int>& nums){
        int n = nums.size();
        if(n < 2) return false;
        int checkPos = n - 2 ;
        while(checkPos >= 0 && nums[checkPos] >= nums[checkPos + 1]) checkPos--;
        if(checkPos < 0) {
            return false;
        }
        int swapPos = checkPos + 1;
        while(swapPos < n && nums[swapPos] > nums[checkPos]) swapPos++;
        swapPos--;
        swap(nums[swapPos],nums[checkPos]);
        sort(nums.begin() + checkPos + 1, nums.end());
        return true;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(nextPermutation(nums)){
            res.push_back(nums);
        }
        return res;
    }
};
