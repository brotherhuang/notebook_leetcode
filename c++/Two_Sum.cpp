/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                if(nums[i] * 2 == target){
                    res.push_back(mp[nums[i]]);
                    res.push_back(i);
                    return res;
                }
            }
            else mp[nums[i]] = i;
        }
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            if(nums[start] + nums[end] == target){
                res.push_back(mp[nums[start]]);
                res.push_back(mp[nums[end]]);
                return res;
            }
            else if(nums[start] + nums[end] < target) start++;
            else end--;
        }
        return res;
    }
};


class Solution {
public:
    struct towSumHelp
    {
        int value;
        int index;
        towSumHelp(int val, int i) : value(val), index(i) {}
    };
    struct less_than_key
    {
        inline bool operator() (const towSumHelp& struct1, const towSumHelp& struct2)
        {
            return (struct1.value < struct2.value);
        }
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<towSumHelp> towSumList;
        for(int i = 0; i < nums.size(); i++){
            towSumList.push_back(towSumHelp(nums[i],i));
        }
        sort(towSumList.begin(),towSumList.end(),less_than_key());
        int start = 0;
        int end = towSumList.size() - 1;
        int sum = towSumList[start].value + towSumList[end].value;
        while(sum != target){
            if(sum > target) end -- ;
            else start ++;
            sum = towSumList[start].value + towSumList[end].value;
        }
        vector<int> res= {towSumList[start].index,towSumList[end].index};
        return res;
    }
};
