/*Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


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
Output: [-34, -14, -10, -10, 10] */
class Solution {
public:
    int calculate(int a, int b, char op)  {
        if(op == '+'){
            return a+b;
        }
        else if(op == '-'){
            return a - b;
        }
        else{
            return a*b;
        }
    }
    vector<int> diffWaysToCompute(string input) {
        // check if just numer
        int number = 0; int i = 0;
        for(; i < input.size() && isdigit(input[i]); i++){
            number = number * 10 + input[i] - '0';
        }
        vector<int> res;
        res.push_back(number);
        if(i == input.size()){
            return res;
        }
        vector<int> diffWays, lefts, rights;
        for(int i = 0; i< input.size(); i++){
              if(isdigit(input[i])) continue;
              lefts = diffWaysToCompute(input.substr(0, i));
              rights = diffWaysToCompute(input.substr(i + 1, input.length() - i - 1));
               for(int j = 0; j < lefts.size(); ++j)
                 for( int k =0; k < rights.size(); ++k){
                   diffWays.push_back(calculate(lefts[j], rights[k], input[i]));
                 }
         }
         return diffWays;
    }
};
