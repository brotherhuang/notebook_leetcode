/*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem. */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redIndex = 0;
        int blueIndex = nums.size() -1;
        int i = 0;
        while(i < blueIndex +1)
        {
            if(nums[i] == 0)
            {
               std::swap(nums[i],nums[redIndex]);
               i++;
               redIndex++;
               continue;
            }
            if(nums[i] == 2)
            {
                std::swap(nums[i],nums[blueIndex]);
                blueIndex--;
                continue;
            }
            i++;
        }
    }
};