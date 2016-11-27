/*
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
*/
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> used;
        set<string> valid;
        for(auto s : bank) valid.insert(s);
        vector<string> current;
        current.push_back(start);
        used.insert(start);
        valid.erase(start);
        int res = 0;
        while(!current.empty()){
            vector<string> next;
            for(int i = 0; i < current.size(); i++){
                for(int j = 0; j < current[i].size(); j++){
                    vector<char> can = {'A','T','C','G'};
                    for(int k = 0; k < 4; k++){
                        string poss = current[i];
                        poss[j] = can[k];
                        if(used.find(poss) ==  used.end() && valid.find(poss) != valid.end()){
                            used.insert(poss);
                            valid.erase(poss);
                            next.push_back(poss);
                        }
                    }
                }
            }
            res++;
            for(int i = 0; i < next.size(); i++){
                if(next[i].compare(end) == 0) return res;
            }
            current = next;
        }
        return -1;
    }
};
