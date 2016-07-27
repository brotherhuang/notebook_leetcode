""" Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint. """
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0 : return 0
        start = 0
        sum = 0
        res = sys.maxint
        for i in range(len(nums)):
            sum += nums[i]
            while sum >= s:
                res = min(res, i - start + 1)
                sum -= nums[start]
                start += 1
        if res == sys.maxint: return 0
        return res
