/* Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max3[3] = {LLONG_MIN , LLONG_MIN ,LLONG_MIN};
        for(int i = 0; i < nums.size(); i++){
            long long current = nums[i];
            bool needChange = false;
            if(current == max3[0]) continue;
            if(current > max3[0]) {
                needChange = true;
            }
            if(needChange) swap(current, max3[0]);
            needChange = false;
            if(current == max3[1]) continue;
            if(current > max3[1]) {
                needChange = true;
            }
            if(needChange) swap(current, max3[1]);
            needChange = false;
            if(current == max3[2]) continue;
            if(current > max3[2]) {
                needChange = true;
            }
            if(needChange) swap(current, max3[2]);
        }
        if(max3[2] == LLONG_MIN) return max3[0];
        return max3[2];
    }
};
