/* Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. */
class Solution {
public:
    string minWindow(string S, string T) {
     int lens = S.size(), lent = T.size();
        queue<int> Q;
        int srcCnt[256] = {0};
        int foundCnt[256] = {0};
        for(int i = 0; i < lent; i++)
            srcCnt[T[i]]++;
        int hasFound = 0;
        int winStart = -1, winEnd = lens;
        for(int i = 0; i < lens; i++)
            if(srcCnt[S[i]] != 0)
            {
                Q.push(i);
                foundCnt[S[i]]++;
                if(foundCnt[S[i]] <= srcCnt[S[i]])hasFound++;
                if(hasFound == lent)
                {
                    int k;
                    do
                    {
                        k = Q.front();
                        Q.pop();
                        foundCnt[S[k]]--;
                    }
                    while(srcCnt[S[k]] <= foundCnt[S[k]]);
                    if(winEnd - winStart > i - k)
                    {
                        winStart = k;
                        winEnd = i;
                    }
                    hasFound--;
                }
            }
        return winStart != -1 ? S.substr(winStart, winEnd - winStart +1) : "";
    }
};
