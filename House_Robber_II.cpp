/* Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police. */
class Solution {
public:
    int robWithStartAndEnd(vector<int>& nums, int start, int end){
        if(nums.size() == 0) return 0;
        if(start == end ) return nums[start];
        if(end - start == 1) return max(nums[start],nums[end]);
        vector<int> res ={nums[start], max(nums[start],nums[start + 1])};
        for(int i = start + 2; i <= end ; i++){
            res.push_back(max(nums[i] + res[i-2 - start], res[i-1 - start]));
        }
        return res.back();

    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        return max(robWithStartAndEnd(nums, 1, nums.size()-1), robWithStartAndEnd(nums, 0, nums.size() - 2));
    }
};
