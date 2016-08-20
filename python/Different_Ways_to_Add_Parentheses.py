"""
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
"""
class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        def cal(a,b,op):
            if op == '-':
                return a - b
            elif op == '+':
                return a + b
            elif op == '*':
                return a * b
        i = 0
        num = 0
        res = []
        while i < len(input) and input[i].isdigit():
            num = num * 10 + int(input[i])
            i += 1
        if i == len(input) :
            res.append(num)
            return res
        for i in range(len(input)):
            if input[i].isdigit() : continue
            left = input[0:i]
            right = input[i + 1 :]
            leftList = self.diffWaysToCompute(left)
            rightList = self.diffWaysToCompute(right)
            for l in leftList:
                for r in rightList:
                    res.append(cal(l,r,input[i]))
        return res            
