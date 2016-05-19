/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentCount = 1;
        int currentNum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == currentNum){
                currentCount ++;
            }
            else{
                currentCount -- ;
            }
            if(currentCount == 0){
                currentNum = nums[i];
                currentCount = 1;
            }
        }
        return currentNum;
    }
};
