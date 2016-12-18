/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you can save this little girl or not.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/
class Solution {
public:
    bool dfs(vector<int> nums, int start, vector<int> side){
            if (start == nums.size()) return true;
            for (int i = 0; i < 4; i++) {
                if (side[i] < nums[start]) continue;
                side[i] -= nums[start];
                if (dfs(nums,start + 1, side)) return true;
                side[i] += nums[start];
            }
            return false;
    }
    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        int len = sum / 4;
        vector<int> side(4, len);
    /*
        function<bool(int)> dfs;
        dfs = [&](int start) {
            if (start == nums.size()) return true;
            for (int i = 0; i < 4; i++) {
                if (side[i] < nums[start]) continue;
                side[i] -= nums[start];
                if (dfs(start + 1)) return true;
                side[i] += nums[start];
            }
            return false;
        };*/
        return dfs(nums,0, side);
    }
};
