"""
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
"""
class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        current = 1
        for i in range(0,n):
            res.append(current)
            if current * 10 <= n :
                current *= 10
            else :
                if current >= n : current /= 10
                current += 1
                while current % 10 == 0 : current /= 10
        return res      
