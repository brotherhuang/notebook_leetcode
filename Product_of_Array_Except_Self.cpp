/* Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6]. */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prodForward;
        vector<int> prodBackward;
        int prodf = 1;
        int prodb = 1;
        for(int i = 0; i < nums.size(); i++){
            prodf *= nums[i];
            prodb *= nums[nums.size() - i - 1];
            prodForward.push_back(prodf);
            prodBackward.push_back(prodb);
        }
        vector<int> res(nums.size(),0);
        res[0] = prodBackward[nums.size() - 2];
        res.back() = prodForward[nums.size() - 2];
        for(int i = 1; i <= nums.size() - 2; i++) {
              res[i] = prodForward[i - 1] * prodBackward[nums.size() - i - 2];
        }
        return res;
    }
};
