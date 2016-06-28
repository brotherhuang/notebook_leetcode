/* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"]. */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() <= 10)
        {
            return res;
        }
        unordered_set<string> candidate;
        unordered_set<string> rescandidate;
        for(size_t i = 0; i <= s.size() - 10; i++)
        {
            string p = s.substr(i,10);
            if(candidate.find(p) != candidate.end()){
                if(rescandidate.find(p) == rescandidate.end()){
                      res.push_back(p);
                      rescandidate.insert(p);
                }
            }
            else candidate.insert(p);
        }
        return res;
    }
};
