""" Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999."""

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        values = [ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 ]
        romans = [ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" ]
        res = ""
        for i in range(len(values)):
            while num >= values[i]:
                num -= values[i]
                res += romans[i]
        return res

        
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roman = ['I','V','X','L','C','D','M']
        res = ""
        base = 1000
        index = 6
        while base > 0 :
            current = num / base;
            if current <= 3:
                res =  res + roman[index] * current
            elif current == 4:
                res =  res + roman[index] + roman[index+ 1]
            elif current == 5:
                res = res + roman[index+ 1]
            elif current <= 8 :
                res =  res + roman[index+ 1] + roman[index] * (current - 5)
            else:
                res =  res + roman[index] + roman[index + 2]
            num = num % base
            base = base /10
            index -= 2
        return res
