"""
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
"""
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def getSum(candidates, target, current, res):
            if target == 0 :
                res.append(current[:])
                return
            if target < candidates[0] : return
            for i in  range(len(candidates)) :
                if candidates[i] <= target:
                    if len(current) == 0 or candidates[i] >= current[-1]:
                        current.append(candidates[i])
                        getSum(candidates, target - candidates[i], current, res)
                        current.pop()
        candidates.sort()
        current = []
        res = []
        getSum(candidates, target, current, res)
        return res
