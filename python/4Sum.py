'''Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]'''
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
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
        if len(nums) < 4 : return res
        nums.sort()
        first = nums[0] - 1
        second = nums[0] - 1
        third = nums[0] - 1
        for i in range(len(nums)):
            if first == nums[i]: continue
            first = nums[i]
            for j in range(i + 1, len(nums)):
                if second == nums[j]: continue
                second = nums[j]
                for k in range(j + 1, len(nums)):
                    if third == nums[k]: continue
                    third = nums[k]
                    left = target - first -  second -  third
                    if left >= nums[k] and left <= nums[-1] and binarySearch(k + 1, len(nums) - 1, left, nums):
                        res.append([first, second,third, left])
                third = nums[0] - 1
            second = nums[0] - 1
        return res            
