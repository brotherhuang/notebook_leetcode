/* Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets. */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum += num;
        vector<int> current(sum + 1, -1);
        current[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++){
            vector<int> next(sum + 1, -1);
            for(int j = 0; j < current.size(); j++){
                if(current[j] == 1){
                    next[ j + nums[i]] = 1;
                    next[ abs(j -nums[i])] = 1;
                }
            }
            current = next;
        }
        return current[0] == 1;
    }
};
