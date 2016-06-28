/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. */
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        vector<int> checkedList;
        for(int  i= 0; i < s.size(); i++){
            if(s[i] == '('){
                checkedList.push_back(i);
            }
            else{
                if(checkedList.size() > 0 && s[checkedList.back()] == '('){
                   checkedList.pop_back();
                   int currentLen = i + 1;
                   if(checkedList.size() > 0) currentLen = i - checkedList.back();
                   maxlen = max(maxlen, currentLen);
                }
                else {
                    checkedList.push_back(i);
                }
            }
        }
        return maxlen;
    }
};	