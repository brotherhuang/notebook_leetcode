/* Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]] += 1;
            }
            else{
                mp[nums[i]] = 1;
            }
        }
        int totalSet = 1;
        vector<int> accuProd;
        for ( auto it = mp.begin(); it != mp.end(); ++it){
             totalSet *= (it->second + 1);
             accuProd.push_back(totalSet);
         }
        for(int i = 0; i < accuProd.size(); i++){
            accuProd[i] = totalSet /accuProd[i];
        }
        vector<vector<int>> res;
        for(int i = 0; i < totalSet; i++){
            vector<int> subSet;
            int currentSize = i;
            int valueIndex = 0;
            for(auto it = mp.begin(); it!= mp.end(); ++it){
                int currentNum = currentSize / accuProd[valueIndex];
                for(int j = 0; j < currentNum; j++){
                    subSet.push_back(it->first);
                }
                currentSize = currentSize % accuProd[valueIndex];
                valueIndex++;
            }
            sort(subSet.begin(),subSet.end());
            res.push_back(subSet);
        }
        return res;
    }
};
