/* Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n == 0) return 0;
        if(m == 0) return -1;
        for(int i = 0; i <=m-n; i++){
            for(int j = 0; j <=n; j++){
                if(j == n) return i;
                if(needle[j] != haystack[i+j]) break;
            }
        }
        return -1;
    }
};
