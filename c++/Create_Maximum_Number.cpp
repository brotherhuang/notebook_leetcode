/* Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9] */
class Solution {
public:
    vector<int> findkNumer(vector<int> num, int k){
        vector<int> res;
        if(k == 0) return res;
        int lastPos = 0;
        while(res.size() < k){
            int maxValue = INT_MIN;
            int maxIndex = -1;
            for(int i = lastPos ; i <= num.size() - (k - res.size()); i++){
                maxIndex = maxValue < num[i] ? i : maxIndex;
                maxValue = maxValue < num[i] ? num[i] : maxValue;
            }
            res.push_back(maxValue);
            lastPos  = maxIndex + 1;
        }
        return res;
    }
    vector<int> mergeVector(vector<int> nums1, vector<int> nums2){
      vector<int>res;
      while(nums1.size() + nums2.size()){
          //lexi compare
          vector<int>& temp = nums1>nums2?nums1:nums2;
          res.push_back(temp[0]);
          temp.erase(temp.begin());
      }
      return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        if(k == 0 || k > nums1.size() + nums2.size()) return res;
        if(nums1.size() == 0) return findkNumer(nums2,k);
        if(nums2.size() == 0) return findkNumer(nums1,k);
        for(int i = 0; i <= k ; i++){
            if( i <= nums1.size() && (k - i) <= nums2.size()){
                vector<int> newVector = mergeVector(findkNumer(nums1, i), findkNumer(nums2, k-i));
                if(res.size() == 0) res = newVector;
                else res = max(res, newVector);
            }
        }
        return res;
    }
};

/*-------------------------------*/
bool compareVector(vector<int> num1, vector<int> num2){
    for(int i = 0; i < num1.size(); i++){
        if(num1[i] == num2[i]) continue;
        else if(num1[i] > num2[i]) return true;
        else return false;
    }
    return true;
}
