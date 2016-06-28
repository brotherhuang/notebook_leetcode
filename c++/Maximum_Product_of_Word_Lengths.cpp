/* Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
		int n = words.size();
		vector<vector<int> > charlist(n, vector<int>(26, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < words[i].size(); j++)
				charlist[i][words[i][j] - 'a'] ++;
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				bool flag = true;
				for (int k = 0; k < 26; k++) {
					if (charlist[i][k] != 0 && charlist[j][k] != 0) {
						flag = false;
						break;
					}
				}
				if (flag && words[i].size() * words[j].size()  > res)
					res = words[i].size() * words[j].size();
			}
		}
		return ans;
    }
};
