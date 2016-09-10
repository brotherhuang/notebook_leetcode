"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
"""
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def findKthNumber(nums1, nums2, k):
            n = len(nums1)
            m = len(nums2)
            if n > m : return  findKthNumber(nums2, nums1, k)
            if n == 0 : return nums2[k-1]
            if k == 1 : return min(nums1[0], nums2[0])
            pa = min(k/2, n)
            pb = k - pa
            if nums1[pa - 1] < nums2[pb - 1]:
                parta = nums1[pa:]
                return findKthNumber(parta, nums2, k - pa)
            elif nums1[pa - 1] > nums2[pb - 1]:
                partb = nums2[pb:]
                return findKthNumber(nums1, partb, k - pb)
            else : return nums1[pa-1];
        n = len(nums1)
        m = len(nums2)
        if n + m == 0 : return 0
        if (n + m) % 2 == 1 : return findKthNumber(nums1, nums2, (n+m)/2 + 1)
        else : return (findKthNumber(nums1, nums2, (n+m)/2) + findKthNumber(nums1, nums2, (n+m)/2 + 1))/2.0
