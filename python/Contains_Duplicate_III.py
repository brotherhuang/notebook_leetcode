"""
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
"""
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        pairList = []
        for i in range(len(nums)):
            pairList.append([nums[i], i])
        pairList.sort(key=lambda pair: pair[0])
        start = 0
        for i in range(len(pairList)):
            j = i + 1
            while j < len(pairList) and pairList[j][0] - pairList[i][0] <= t:
                if abs(pairList[j][1] - pairList[i][1]) <= k : return True
                j += 1
        return False        
