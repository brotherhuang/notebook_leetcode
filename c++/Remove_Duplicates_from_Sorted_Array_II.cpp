/* Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return nums.size();
        }
        int current = nums[0];
        int currentCount = 1;
        for(size_t i = 1; i < nums.size(); i++){
            if(current == nums[i]){
                if(currentCount == 1){
                    currentCount++;
                }
                else{
                    nums.erase(nums.begin() + i);
                    i--;
                }
            }
            else{
                current = nums[i];
                currentCount = 1;
            }
        }
        return nums.size();
    }
};
