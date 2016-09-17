"""
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). """
    class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3 : return sys.maxsize
        nums.sort()
        minDiff = sys.maxsize
        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1
            while(left < right):
                diff = nums[i]+nums[left]+nums[right]-target
                if abs(diff) < abs(minDiff): minDiff = diff
                if diff == 0 : break
                elif diff < 0 : left += 1
                else : right -= 1
        return target + minDiff       
