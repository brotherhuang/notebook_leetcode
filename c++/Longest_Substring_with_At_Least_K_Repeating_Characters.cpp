/* Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times. */
class Solution {
public:
    int longestSubstring(string s, int k) {
		if (s.length() < k)
			return 0;

		int result = s.length();
		int chars[26] = { 0, };
		for (int i = 0; i < s.length(); i++)
			chars[s[i] - 'a']++;

		int i = 0;
		while (i < s.length() && chars[s[i] - 'a'] >= k)
			i++;

		if (i == s.length())
			return s.length();

		return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i + 1), k));
    }
};
