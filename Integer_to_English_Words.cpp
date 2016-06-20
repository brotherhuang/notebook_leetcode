/* Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven" */
class Solution {
public:
    string lessThanThousand(int num){
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        if(a > 0) res = v1[a] + " Hundred";
        if(b < 20 && b > 0) {
            res = res.empty()?v1[b]:res + " "+ v1[b];
        }
        else {
            res = res.empty()?v2[b/10]:res + " "+ v2[b/10];
            if(c > 0) res = res.empty()?v1[c]:res + " "+ v1[c];
        }
        if(res.back() == ' ') res.pop_back();
        return res;

    }
    string numberToWords(int num) {
	    string res;
	    if(num / 1000000000) res = res + lessThanThousand(num / 1000000000) + " Billion ";
	    num = num % 1000000000;
	    if(num / 1000000) res = res + lessThanThousand(num / 1000000) + " Million ";
	    num = num % 1000000;
	    if(num / 1000) res = res + lessThanThousand(num / 1000) + " Thousand ";
	    num = num % 1000;
	    res = res + lessThanThousand(num);
        while (res.back() == ' ') res.pop_back();
        return res.empty() ? "Zero" : res;
    }

};
