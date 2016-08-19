"""
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
] """
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def getCombine(start, k, n,current, res):
            if len(current) == k:
                res.append(current[:])
                return
            for i in range(start,n):
                current.append(i+1)
                getCombine(i+1, k, n, current, res)
                current.pop()
        current = []
        res = []
        needRemove = False
        if k > n - k :
            k = n - k
            needRemove = True
        getCombine(0,k,n,current,res)
        ress = []
        if needRemove:
            for ele in res:
                newele = []
                for i in range(1, n+1):
                    if ele.count(i) != 1 :
                        newele.append(i)

                ress.append(newele)
            return ress
        return res
                
