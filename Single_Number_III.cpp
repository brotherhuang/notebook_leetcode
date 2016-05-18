/* Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity? */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()) {
                mp[nums[i]] += 1;
            }
            else {
                mp[nums[i]] = 1;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == 1){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
