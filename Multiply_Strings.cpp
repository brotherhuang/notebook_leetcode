/* Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger. */
class Solution {
public:
    string addString(string s1, string s2){
    	reverse(s1.begin(), s1.end());
    	reverse(s2.begin(), s2.end());
        string res;
        if(s1.size() > s2.size()) swap(s1,s2);
        int containTen = 0;
        for(int i = 0; i < s1.size(); i++){
            int p0 = s1[i] - '0';
            int p1 = s2[i] -'0';
            int current = p0 + p1 + containTen;
            containTen = current / 10;
            res.push_back(current % 10 + '0');
        }
        for(int i = s1.size(); i < s2.size(); i++){
            int p0 = s2[i] - '0';
            int current = p0 + containTen;
            containTen = current / 10;
            res.push_back(current % 10 + '0');
        }
        if(containTen == 1) res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
    string multiString(string s1, char s2){
         reverse(s1.begin(), s1.end());
         string res;
         if(s2 == '0') return "0";
         int containTen = 0;
         for(int i = 0; i < s1.size(); i++){
            int p0 = s1[i] - '0';
            int p1 = s2 -'0';
            int current = p0*p1 + containTen;
            containTen = current / 10;
            res.push_back(current % 10 + '0');
        }
        if(containTen != 0) res.push_back(containTen + '0');
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        if(num2.compare("0") == 0 || num1.compare("0") == 0) return "0";
        string res;
        for(int i = 0; i <num1.size(); i++){
            string appendString(num1.size() - i - 1,'0');
            res = addString(res, multiString(num2 + appendString, num1[i]));
        }
        return res;
    }
};
