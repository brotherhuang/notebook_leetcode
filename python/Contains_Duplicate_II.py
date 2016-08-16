"""
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. """
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        mp = {}
        for i in range(len(nums)):
            if mp.has_key(nums[i]) and i - mp[nums[i]] <= k: return True
            else: mp[nums[i]] = i
        return False    
