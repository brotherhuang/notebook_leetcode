/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".*/
class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] =='A' || s[i] =='a' || s[i] =='e' || s[i] =='E' || s[i] =='I' || s[i] =='i' || s[i] =='O' || s[i] =='o' || s[i] =='U' || s[i] =='u' )
            {
                vowels.push_back(s[i]);
                count++;
            }
        }
        //int current = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] =='A' || s[i] =='a' || s[i] =='e' || s[i] =='E' || s[i] =='I' || s[i] =='i' || s[i] =='O' || s[i] =='o' || s[i] =='U' || s[i] =='u' )
            {
                s[i] = vowels[count - 1];
                count --;
            }
        }
        return s;
    }
};
