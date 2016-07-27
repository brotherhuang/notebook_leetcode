/* Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
] */
class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size() - 1;
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void findPalindrome(string s, int pos, vector<string> cut, vector<vector<string>> &res){
        if(pos == s.size()){
            res.push_back(cut);
            return;
        }
        for(int i = pos; i < s.size(); i++){
            string currentCut = s.substr(pos, i - pos + 1);
            if(isPalindrome(currentCut)){
                cut.push_back(currentCut);
                findPalindrome(s, i + 1, cut, res);
                cut.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.size() == 0) return res;
        vector<string> cut;
        findPalindrome(s, 0, cut, res);
        return res;
    }
};
