/* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. */
class Solution {
public:
    bool findSolution(string s1, string s2, string s3, int pos1, int pos2, int pos3){
        if(pos3 == s3.size()){
            return true;
        }
        bool hasSolution = false;
        if(s1[pos1] == s3[pos3]) hasSolution = hasSolution || findSolution(s1,s2,s3, pos1 + 1, pos2, pos3+1);
        if(hasSolution) return hasSolution;
        if(s2[pos2] == s3[pos3]) hasSolution = hasSolution || findSolution(s1,s2,s3, pos1, pos2 + 1, pos3+1);
        return hasSolution;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
         return findSolution(s1,s2,s3,0,0,0);
    }
};
