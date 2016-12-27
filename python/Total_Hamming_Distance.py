"""
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
Subscribe to see which companies asked this question
"""
class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2 : return 0
        res = 0
        while True:
            nonZero = 0
            numZero = 0
            numOne = 0
            for i in range(len(nums)):
                if nums[i] % 2 == 0 : numZero += 1
                else: numOne += 1
                nums[i] /= 2
                if nums[i] > 0 : nonZero += 1
            res += numZero * numOne
            if nonZero == 0 : return res
        return res
            
