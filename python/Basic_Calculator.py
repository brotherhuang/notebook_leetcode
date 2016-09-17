"""
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
"""
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        def eval(s):
            if len(s) == 0: return 0
            s = s + '+'
            res = 0
            currentNum = 0
            hasFirst = False
            lastOP = '+'
            for char in s:
                if char == '+' or char == '-':
                    if hasFirst:
                        if lastOP == '+' : res = res + currentNum
                        else: res = res - currentNum
                        currentNum = 0
                        lastOP = char
                    else:
                        hasFirst = True
                        res = currentNum
                        currentNum = 0
                        lastOP = char
                else:
                    currentNum = currentNum * 10 + int(char)
            return res
        res = []
        empty = ""
        res.append(empty)
        for char in s:
            if char == ' ': continue
            elif char == '(':
                res.append(empty)
            elif char == ')':
                current = eval(res[-1])
                res.pop()
                if current < 0 and len(res[-1]) > 0 and res[-1][-1] == '+':
                    res[-1] = res[-1][:-1] + '-'
                    current = - current
                if current < 0 and len(res[-1]) > 0 and res[-1][-1] == '-':
                    res[-1] = res[-1][:-1] + '+'
                    current = - current
                res[-1] = res[-1] + str(current)
            else: res[-1] = res[-1] + char
        return    eval(res[0])
