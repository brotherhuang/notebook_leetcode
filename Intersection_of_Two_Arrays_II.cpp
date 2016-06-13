/* Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once? */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> interRes;
        vector<bool> checked(nums1.size(),false);
        for(int num2 : nums2){
            for(int i = 0; i <nums1.size(); i++){
                if(num2 == nums1[i] && !checked[i]){
                    interRes.push_back(num2);
                    checked[i] = true;
                    break;
                }
            }
        }
        return interRes;
    }
};