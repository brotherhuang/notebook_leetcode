/* Write a function to find the longest common prefix string amongst an array of strings. */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return res;
        for(int i = 0; i < strs[0].size(); i++){
            bool isCommon = true;
            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != strs[0][i]){
                    isCommon = false;
                    break;
                }
            }
            if(!isCommon) break;
            res.push_back(strs[0][i]);
        }
        return res;
    }
};
