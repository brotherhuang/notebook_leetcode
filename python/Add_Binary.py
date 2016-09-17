"""
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". """
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        def binartAdd(c0, c1, carry):
            cur = ord(c0) - ord('0') + ord(c1) - ord('0') + carry
            if cur == 3 :
                return '1', 1
            elif cur == 2:
                return '0', 1
            elif cur == 1:
                return '1', 0
            else :
                return '0', 0
        a = a[::-1]
        b = b[::-1]
        if len(a) > len(b) : a ,b =  b, a
        carry = 0
        res = []
        for i in range(len(a)):
            cur, carry = binartAdd(a[i],b[i],carry)
            res.append(cur)
        for i in range(len(a), len(b)):
            cur, carry = binartAdd(b[i],'0',carry)
            res.append(cur)
        if carry == 1 : res.append('1')
        return ''.join(res[::-1])
        
