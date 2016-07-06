/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not. */
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        vector<char> checkList;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                checkList.push_back(s[i]);
            }
            if(s[i] == ']'){
                if(i > 0 && checkList.back() == '[') checkList.pop_back();
                else return false;
            }
            if(s[i] == '}' ){
                if( i > 0 && checkList.back() == '{') checkList.pop_back();
                else return false;
            }
            if(s[i] == ')'){
                if( i > 0 && checkList.back() == '(') checkList.pop_back();
                else return false;
            }
        }
        return checkList.size() == 0;
    }
};
