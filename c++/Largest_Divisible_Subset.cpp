/* Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8] */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end());
        vector<vector<int>> eachElement(nums.size(), vector<int>(0));
        for(int i = 0; i < nums.size(); i++){
            eachElement[i].push_back(nums[i]);
            int maxIndex = -1;
            int maxSize = 0;
            for(int j = i -1; j >=0; j--){
                if(nums[i] % nums[j] == 0 && eachElement[j].size() > maxSize){
                    maxSize = eachElement[j].size();
                    maxIndex = j;
                }
            }
            if(maxIndex != -1) eachElement[i].insert(eachElement[i].end(), eachElement[maxIndex].begin(),eachElement[maxIndex].end());
            if(eachElement[i].size() > res.size()){
                res = eachElement[i];
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end());
        vector<pair<int, int>> eachElement(nums.size());
        int firstIndex = -1;
        int currentSize = 0;
        for(int i = 0; i < nums.size(); i++){
            eachElement[i].first = 1;
            eachElement[i].second = -1;
            int maxIndex = -1;
            int maxSize = 0;
            for(int j = i -1; j >=0; j--){
                if(nums[i] % nums[j] == 0 && eachElement[j].first > maxSize){
                    maxSize = eachElement[j].first;
                    maxIndex = j;
                }
            }
            if(maxIndex != -1){
                eachElement[i].first += eachElement[maxIndex].first;
                eachElement[i].second = maxIndex;
            }
            if(eachElement[i].first > currentSize){
                firstIndex = i;
                currentSize = eachElement[i].first;
            }
        }
        while(firstIndex != -1){
            res.push_back(nums[firstIndex]);
            firstIndex = eachElement[firstIndex].second;
        }
        return res;
    }
};
