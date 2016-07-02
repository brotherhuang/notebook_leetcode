""" Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array. """
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 1
        res = nums[0]
        for i in range(len(nums)):
            if i == 0: continue
            if nums[i] != res:
                count -= 1
            else: count += 1
            if count == 0 :
                res = nums[i]
                count = 1
        return res    
