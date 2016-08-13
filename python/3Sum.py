''' Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]'''
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def binarySearch(start, end, target, nums):
            while(start <= end):
                mid =  start + (end - start)/2
                if nums[mid] == target : return True
                elif  nums[mid] < target: start = mid + 1
                else : end = mid - 1
            return False
        res = []
        if len(nums) < 3 : return res
        nums.sort()
        first = nums[0] - 1
        second = nums[0] - 1
        for i in range(len(nums)):
            if first == nums[i]: continue
            first = nums[i]
            for j in range(i + 1, len(nums)):
                if second == nums[j]: continue
                second = nums[j]
                left = - first - second
                if(binarySearch(j + 1, len(nums) - 1, left, nums)) :
                    res.append([first, second,left])
        return res
