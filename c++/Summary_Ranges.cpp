/*Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int start = nums[0];
        int end = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == end + 1){
                end = nums[i];
            }
            else{
                if(start == end) {
                    string s = to_string(start);
                    res.push_back(s);
                }
                else{
                    string s = to_string(start) + "->" + to_string(end);
                    res.push_back(s);
                }
                start = nums[i];
                end = nums[i];
            }
        }
        if(start == end) {
            string s = to_string(start);
            res.push_back(s);
        }
        else{
            string s = to_string(start) + "->" + to_string(end);
            res.push_back(s);
        }
        return res;
    }
};
