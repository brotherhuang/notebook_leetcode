/* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. */
class Solution {
public:
    void findBreak(string s, int pos, vector<string> cut, vector<string>& res, unordered_set<string> wordDict, vector<bool>& possible){
        if(pos == s.size() && cut.size() != 0){
            string current = cut[0];
            for(int i = 1; i < cut.size(); i++){
                current = current + " " + cut[i];
            }
            res.push_back(current);
            return;
        }
        string current;
        for(int i = pos; i < s.size(); i++){
            current.push_back(s[i]);
            if(wordDict.count(current) != 0 && possible[i+1]){
                cut.push_back(current);
                int beforeChange = res.size();
                findBreak(s, i + 1, cut, res, wordDict,possible);
                if(res.size() == beforeChange) possible[i+1] = false;
                cut.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        vector<string> cut;
        vector<bool> possible(s.size() + 1, true);
        findBreak(s,0,cut,res, wordDict,possible);
        return res;
    }
};
