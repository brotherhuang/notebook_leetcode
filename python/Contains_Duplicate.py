"""Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct."""
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if nums is None : return False
        mp = {}
        for i in nums :
            if not mp.get(i):
                mp[i] = True
            else:
                return True
        return False
