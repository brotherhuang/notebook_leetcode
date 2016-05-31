/* Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true. */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
         unordered_map<char,char> mp;
         for(int i = 0; i < s.size(); i++){
             if(mp.find(s[i]) != mp.end()){
                 if(mp[s[i]] != t[i]){
                     return false;
                 }
             }
             else{
                 mp[s[i]] = t[i];
             }
         }
         unordered_map<char,char> mpi;
         for(int i = 0; i < t.size(); i++){
             if(mpi.find(t[i]) != mpi.end()){
                 if(mpi[t[i]] != s[i]){
                     return false;
                 }
             }
             else{
                 mpi[t[i]] = s[i];
             }
         }
         return true;
    }
};
