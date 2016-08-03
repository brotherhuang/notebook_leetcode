/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i  = 0; i < nums.size(); i++){
            mp.insert(nums[i]);
        }
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i]) == 0) continue;
            mp.erase(nums[i]);
            int len = 1;
            int backward = nums[i] - 1;
            while(mp.find(backward) != mp.end()){
                mp.erase(backward);
                backward--;
                len++;
            }
            int forward = nums[i] + 1;
            while(mp.find(forward) != mp.end()){
                mp.erase(forward);
                forward++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
