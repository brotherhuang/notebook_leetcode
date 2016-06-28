/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6 */
  class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand;
           for(int i =0; i< tokens.size(); i++)
           {
                if ((tokens[i][0] == '-' && tokens[i].size()>1) //negative number
                || (tokens[i][0] >= '0' && tokens[i][0] <= '9')) //positive number
                {
                     operand.push(atoi(tokens[i].c_str()));
                    continue;
                }
                int op1 = operand.top();
               operand.pop();
                int op2 = operand.top();
                 operand.pop();
                if(tokens[i] == "+") operand.push(op2+op1);
                if(tokens[i] == "-") operand.push(op2-op1);
                if(tokens[i] == "*") operand.push(op2*op1);
               if(tokens[i] == "/") operand.push(op2/op1);
          }
          return operand.top();
    }
};
