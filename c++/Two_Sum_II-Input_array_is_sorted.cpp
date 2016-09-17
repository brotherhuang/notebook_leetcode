/* Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index0 = 0;
        int index1 = numbers.size() - 1;
        vector<int> res;
        while(index0 < index1){
            if(numbers[index0] + numbers[index1] == target){
                res.push_back(index0 + 1);
                res.push_back(index1 + 1);
                return  res;
            }
            else if(numbers[index0] + numbers[index1] < target){
                index0 ++;
            }
            else index1--;
        }
        return res;
    }
};
