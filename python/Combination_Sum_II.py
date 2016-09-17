"""
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
] """
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def getCombinartion(candidates, start, target, current, res):
            if target == 0 :
                res.append(current[:])
                return
            if start >= len(candidates) or target < candidates[start] : return
            pre = -1
            for i in  range(start, len(candidates)) :
                if candidates[i] != pre and candidates[i] <= target:
                    if len(current) == 0 or candidates[i] >= current[-1]:
                        current.append(candidates[i])
                        getCombinartion(candidates, i + 1, target - candidates[i], current, res)
                        pre = candidates[i]
                        current.pop()
        candidates.sort()
        current = []
        res = []
        getCombinartion(candidates, 0, target, current, res)
        return res
