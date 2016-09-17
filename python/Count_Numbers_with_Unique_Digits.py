"""
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Show Hint
 """
 class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = min(n,10);
        dp = [9] * (n + 1);
        dp[0] = 1;
        for i in range(2, n+1):
            for x in range(9, 10 - i, -1):
                dp[i] *= x
        ans = 0;
        for ele in dp:
            ans += ele
        return ans;
