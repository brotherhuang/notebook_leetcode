/* Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]*/
class Solution {
public:
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            if (t[i] == ')' && cnt-- == 0) return false;
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(s);
        ++visited[s];
        bool found = false;
        while (!q.empty()) {
            s = q.front(); q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i + 1);
                if (visited.find(t) == visited.end()) {
                    q.push(t);
                    ++visited[t];
                }
            }
        }
        return res;
    }
};
