"""
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
"""
class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def countBit(num):
            res = 0
            while num > 0:
                res += num % 2
                num /= 2
            return res
        res = []
        for i in range(0,12):
            for j in range(0,60):
                if(countBit(i) + countBit(j) == num):
                    hour = str(i)
                    min = str(j)
                    if j < 10 : min = '0' + min
                    res.append(hour + ':' + min)
        return res            
