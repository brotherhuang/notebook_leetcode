"""
Description:

Count the number of prime numbers less than a non-negative number, n.
"""
class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2 : return 0
        isPrime = [True] * n
        current = 2
        while current * current < n :
            i = 2
            while current * i < n :
                isPrime[current * i] = False
                i += 1
            current += 1
            while isPrime[current] == False and current * current < n:
                current += 1
        count = 0
        for i in range(2, n):
            if isPrime[i]:
                count += 1
        return count
