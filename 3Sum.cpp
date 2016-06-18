/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
] */
// replace map with binary search
class Solution {
public:
    bool binarySearch(int start, int end, vector<int> nums, int target){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int target = - nums[i] - nums[j];
                if(target >= nums[j] && binarySearch( j + 1, nums.size() - 1, nums, target)){
                    vector<int> ress = {nums[i],nums[j],target};
                    res.push_back(ress);
                }
                while(nums[j + 1] == nums[j] && j + 1 < nums.size()) j++;
            }
            while(nums[i + 1] == nums[i] && i + 1 < nums.size()) i++;
        }
        return res;
    }
};
/* ----------------------------------------------*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> sp;
        for(int i = 0; i < nums.size(); i++){
            if(sp.find(nums[i]) != sp.end()){
                sp[nums[i]]++;
            }
            else sp[nums[i]] = 1;
        }
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            sp[nums[i]]--;
            for(int j = i + 1; j < nums.size(); j++){
                sp[nums[j]]--;
                int target = - nums[i] - nums[j];
                if(target >= nums[j] && sp.find(target) != sp.end() && sp[target] > 0 ){
                    vector<int> ress = {nums[i],nums[j],target};
                    res.push_back(ress);
                }
                sp[nums[j]]++;
                while(nums[j + 1] == nums[j] && j + 1 < nums.size()) j++;
            }
            while(nums[i + 1] == nums[i] && i + 1 < nums.size()) i++;
        }
        return res;
    }
};
