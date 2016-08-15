""""
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]] """
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def getCombination(k,target, current, res):
            if target == 0  and k == 0:
                res.append(current[:])
            if target < 0 or k < 0 :
                return
            for i in range(1,10):
                if i <= target:
                    if len(current) == 0 or i > current[-1]:
                        current.append(i)
                        getCombination(k - 1, target - i , current, res)
                        current.pop()
        current = []
        res = []
        getCombination(k,n, current, res)
        return res
