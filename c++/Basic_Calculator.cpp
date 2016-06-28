/* Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23 */
class Solution {
public:
    int evalString(string s){
	if (s.size() == 0) return 0;
	s.push_back('+');
	int res = 0;
	int currentNum = 0;
	bool hasFirstNum = false;
	char lastOP = '+';
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '+' || s[i] == '-') {
			if (hasFirstNum) { res = lastOP == '+' ? res + currentNum : res - currentNum; currentNum = 0; lastOP = s[i]; }
			else { hasFirstNum = true; res = currentNum; currentNum = 0; lastOP = s[i]; }
		}
		else currentNum = currentNum * 10 + s[i] - '0';
	}
	return res;
    }
    int calculate(string s) {
        vector<string> res;
        string initalString("");
        res.push_back(initalString);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(s[i] == '(') res.push_back(initalString);
            else if(s[i] == ')') {
                int res0 = evalString(res.back());
                res.pop_back();
                if (res0 < 0 && res.back().size() > 0 && res.back().back() == '+') {res.back().back() = '-'; res0 = -res0;}
                if (res0 < 0 && res.back().size() > 0 && res.back().back() == '-') {res.back().back() = '+'; res0 = -res0;}
                res.back() = res.back() + to_string(res0);
            }
            else res.back().push_back(s[i]);
        }
        return evalString(res[0]);
    }
};
