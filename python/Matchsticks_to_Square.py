"""
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you can save this little girl or not.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
"""
class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def dfs(nums, pos, target):
            if pos == len(nums): return True
            for i in range(4):
                if target[i] >= nums[pos]:
                    target[i] -= nums[pos]
                    if dfs(nums, pos+1, target): return True
                    target[i] += nums[pos]
            return False
        if len(nums) < 4 : return False
        numSum = sum(nums)
        nums.sort()
        nums = nums[::-1]
        if numSum % 4 != 0: return False
        target = [numSum/4] * 4;
        return dfs(nums,0, target)
