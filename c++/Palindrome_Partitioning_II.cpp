/* Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.*/




class Solution {
public:
    unordered_map<char, vector<int>> mp;
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
    void findPalindrome(string s, int pos, vector<string> cut, int& minDepth,vector<int>& bestCut){
        if(pos == s.size() && cut.size() <= minDepth){
            minDepth = cut.size();
            return;
        }
        if(cut.size() >= minDepth) return;
        vector<int> candidates = mp[s[pos]];
        for(int i = 0; i < candidates.size(); i++){
            if(candidates[i] < pos) continue;
            string currentCut = s.substr(pos, candidates[i] - pos + 1);
            if(!isPalindrome(currentCut))  continue;
            if(bestCut[candidates[i] + 1] != -1) {
                if(bestCut[candidates[i] + 1] + cut.size() + 1 < minDepth){
                    minDepth = bestCut[candidates[i] + 1] + cut.size() + 1;
                }
                continue;
            }
            cut.push_back(currentCut);
            findPalindrome(s, candidates[i] + 1, cut, minDepth,bestCut);
            bestCut[candidates[i] + 1] = minDepth - cut.size();
            cut.pop_back();
        }
    }
    int minCut(string s) {
        int n = s.size();
        if(n == 0) return 0;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i};
            }
            else  mp[s[i]].push_back(i);
        }
        vector<string> cut;
        vector<int> bestCut(s.size() + 1, -1);
        int minDepth = n;
        findPalindrome(s,0,cut, minDepth,bestCut);
        return minDepth - 1;
    }
};
