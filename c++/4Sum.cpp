/* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
] */
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          sort(nums.begin(),nums.end());
          vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                int targetk = target - nums[i] - nums[j] - nums[k];
                if(targetk >= nums[k+1] && targetk <= nums.back() && binarySearch( k + 1, nums.size() - 1, nums, targetk)){
                    vector<int> ress = {nums[i],nums[j],nums[k],targetk};
                    res.push_back(ress);
                }
                while(nums[k + 1] == nums[k] && k + 1 < nums.size()) k++;
                }
                while(nums[j + 1] == nums[j] && j + 1 < nums.size()) j++;
            }
            while(nums[i + 1] == nums[i] && i + 1 < nums.size()) i++;
        }
        return res;
    }
};
/* --------------------------------------------- */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
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
                for(int k = j + 1; k < nums.size(); k++){
                    sp[nums[k]]--;
                int targetk = target - nums[i] - nums[j] - nums[k];
                if(targetk >= nums[k+1] && targetk <= nums.back()&& sp.find(targetk) != sp.end() && sp[targetk] > 0){
                    vector<int> ress = {nums[i],nums[j],nums[k],targetk};
                    res.push_back(ress);
                }
                sp[nums[k]]++;
                while(nums[k + 1] == nums[k] && k + 1 < nums.size()) k++;
                }
                sp[nums[j]]++;
                while(nums[j + 1] == nums[j] && j + 1 < nums.size()) j++;
            }
            while(nums[i + 1] == nums[i] && i + 1 < nums.size()) i++;
        }
        return res;
    }
};
