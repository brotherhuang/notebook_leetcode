/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> res;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            int tmp = nums[i] > n? nums[i]-n : nums[i];
            if (nums[tmp-1] > n) { // have visited before
                res.push_back(tmp);
            }
            else { // NOT visited before
                nums[tmp-1] += n;
            }
        }
        return res;
    }
};
