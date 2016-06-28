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


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(maxVal < nums[i])
            {
                maxVal = nums[i];
            }
            if(minVal > nums[i])
            {
                minVal = nums[i];
            }
        }
        vector<int> countNum(maxVal - minVal + 1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            countNum[nums[i] - minVal]++;
        }
        vector<int> sortCount = countNum;
        sort(sortCount.begin(), sortCount.end());
        vector<int> res;
        vector<bool> isChecked(countNum.size(), false);
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < countNum.size(); j++)
            {
                if(countNum[j] == sortCount[sortCount.size() - i - 1]&& !isChecked[j])
                {
                    res.push_back(j + minVal);
                    isChecked[j] =true;
                    break;
                }
            }
        }
        return res;
    }
};
