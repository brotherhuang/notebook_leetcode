"""
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers? """
class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        def validString(num0, num1, num):
            startCheck = len(num0) + len(num1)
            if startCheck == len(num): return False
            while startCheck < len(num):
                next = str(long(num0) + long(num1))
                for i in range(len(next)):
                    if startCheck + i >= len(num) or next[i] != num[startCheck + i]: return False
                startCheck += len(next)
                num0 = num1
                num1 = next
            return True
        for i in range(len(num)):
            first = num[0:i+1]
            if first[0] == '0' and len(first) > 1 : continue
            for j in range(i + 1, len(num)):
                second = num[i + 1 : j+1]
                if second[0] == '0' and len(second) > 1 : continue
                if validString(first, second, num) : return True
        return False        
