/* Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() == 0 || k == 0) return res;
        int currentMax = INT_MIN;
        int currentPos = -1;
        for(int i = 0; i < k; i++){
            currentPos = currentMax < nums[i]? i :currentPos;
            currentMax = currentMax < nums[i]? nums[i] :currentMax;
        }
        res.push_back(currentMax);
        for(int i = k ; i < nums.size(); i++){
            if( i - currentPos < k) {
                currentPos = currentMax < nums[i]? i :currentPos;
                currentMax = currentMax < nums[i]? nums[i] :currentMax;
                res.push_back(currentMax);
            }
            else{
                currentMax = INT_MIN;
                currentPos = -1;
                for(int ii = i - k + 1; ii <= i; ii++){
                    currentPos = currentMax < nums[ii]? ii :currentPos;
                    currentMax = currentMax < nums[ii]? nums[ii] :currentMax;
              }
              res.push_back(currentMax);
            }
        }
        return res;
    }
};
