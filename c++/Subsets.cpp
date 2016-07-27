/* Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int totalCount = pow(2,nums.size());
        vector<int> resi(nums.size(),0);
        for(int i = 0; i < totalCount; i++)
        {
            vector<int> resii;
            for(int j = 0; j < resi.size(); j++)
            {
                if(resi[j] == 1)
                {
                    resii.push_back(nums[j]);
                }
            }
            res.push_back(resii);
            int needAdd = 1;
            for(int j = 0; j < resi.size(); j++)
            {
                if(resi[j] + needAdd == 2)
                {
                    resi[j] = 0;
                    needAdd = 1;
                }
                else
                {
                    resi[j] = resi[j] + needAdd;
                    needAdd = 0;
                    break;
                }
            }

        }
        return res;
    }
};
