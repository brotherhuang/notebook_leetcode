/* There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5 */
class Solution {
public:
    double findNthnumber(vector<int>& nums1, vector<int>& nums2, int k){
        int n = nums1.size();
        int m = nums2.size();
        if(n > m){
            return findNthnumber(nums2,nums1,k);
        }
        if(n == 0) return nums2[k-1];
        if(k == 1) return min(nums1[0],nums2[0]);

        int pa = min(k/2,n),pb = k - pa;
        if(nums1[pa - 1] < nums2[pb - 1] ){
             vector<int> a(nums1.begin() + pa, nums1.end());
             return findNthnumber(a,nums2,k - pa);
        }
        else if(nums1[pa - 1] > nums2[pb - 1]){
            vector<int> b(nums2.begin() + pb,nums2.end());
            return findNthnumber(nums1,b,k - pb);
        }
        else return nums1[pa-1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int toalLens = n1 + n2;
        if(toalLens % 2 == 1) return findNthnumber(nums1, nums2,toalLens / 2 + 1);
        else return (findNthnumber(nums1, nums2, toalLens / 2) + findNthnumber(nums1, nums2,toalLens / 2 + 1)) / 2.0;

    }
};
