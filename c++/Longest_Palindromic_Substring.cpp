/* Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring. */
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0){return "";}

        bool table[1000][1000] = {false};

        int maxst=0;
        int maxlen=1;

        for (int i=0;i<n;i++){
            table[i][i]=true;
            maxst=i;
            maxlen=1;
        }
        for (int i=0;i<n-1;i++){
            if (s[i]==s[i+1]){
                table[i][i+1]=true;
                maxst=i;
                maxlen=2;
            }
        }

        for (int len=3; len<=n;len++){
            for (int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if (s[i]==s[j] && table[i+1][j-1]){
                    table[i][j]=true;
                    maxst=i;
                    maxlen=len;
                }
            }
        }
        return s.substr(maxst,maxlen);
    }
};
