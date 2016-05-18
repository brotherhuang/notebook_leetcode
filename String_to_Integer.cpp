/*Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. */


class Solution {
public:
    int myAtoi(string str) {
         int res = 0;
         int i = 0;
         int sign = 1;
         while(str[i] == ' '){ i++;}
         if(str[i] == '-'){
             sign = -1;
             i++;
         }
         else if(str[i] == '+'){ i++; }
         for(; i < str.size(); i++) {
             if(str[i] >= '0' && str[i] <='9') {
                if(sign == 1 && res > INT_MAX/ 10) { return INT_MAX;}
                if(sign == 1 && res == INT_MAX/10 && str[i] - '0' >= 7) { return INT_MAX;}
                if(sign == -1 && -res < INT_MIN/10) { return INT_MIN;}
                if(sign == -1 && -res == INT_MIN /10 && str[i] - '0' >=8) { return INT_MIN;}
                 res = res*10 + str[i] - '0';
             }
             else{ return sign*res;}
         }
         return sign*res;
    }
};