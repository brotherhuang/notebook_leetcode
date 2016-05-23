/* Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2]. */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]] += 1;
            }
            else {
                mp[nums[i]] = 1;
            }
        }
        vector<int> ranks;
        for(int i = 0; i < nums.size(); i++){
            ranks.push_back(mp[nums[i]]);
        }
        sort(ranks.begin(),ranks.end());
        int currentIndex = ranks.size() - 1;
        vector<int> res;
        while(res.size() < k){
            int sizeK = ranks[currentIndex];
            for(int i = 0; i < nums.size(); i++){
                if(mp.find(nums[i]) != mp.end()){
                    if(mp[nums[i]] == sizeK){
                    mp.erase(nums[i]);
                    res.push_back(nums[i]);
                    break;
                    }
                }
            }
            currentIndex -= sizeK;
        }
        return res;
    }
};
