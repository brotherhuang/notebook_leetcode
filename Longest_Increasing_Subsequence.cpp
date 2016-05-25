/* Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity. */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> maxLength(nums.size(),1);
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int currentMax = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    currentMax = (currentMax < maxLength[j])?  maxLength[j] : currentMax;
                }
            }
            maxLength[i] = currentMax + 1;
            res = (res < maxLength[i])?  maxLength[i] : res;
        }
        return res;
    }
};
