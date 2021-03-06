/* Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". */


class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res;
        while(i >= 0 || j >= 0 || carry == 1){
            int current = carry;
            current += i >=0 ? a[i--] -'0' : 0;
            current += j >=0 ? b[j--] -'0' : 0;
            res = char('0' + current % 2) + res;
            carry = current / 2;
        }
        return res;
    }
};



class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.size() < b.size())
        {
            string temp = a;
            a = b;
            b = temp;
        }
            int needadd = 0;
            for(int i = 0; i < b.size(); i++)
            {
                int curretRes = b[i] - '0' + a[i] -'0' + needadd;
                if(curretRes == 0)
                {
                    res = "0" + res;
                    needadd = 0;
                }
                else if(curretRes == 1)
                {
                    res = "1" + res;
                    needadd = 0;
                }
                else if(curretRes == 2)
                {

                   res = "0" + res;
                    needadd = 1;
                }
                else
                {
                     res = "1" + res;
                    needadd = 1;
                }
            }
            for(int i = 0; i < a.size()- b.size(); i++)
            {
                int curretRes = a[b.size() + i] -'0' + needadd;
                if(curretRes == 0)
                {
                    res = "0" + res;
                    needadd = 0;
                }
                else if(curretRes == 1)
                {
                     res = "1" + res;
                    needadd = 0;
                }
                else
                {
                    res = "0" + res;
                    needadd = 1;
                }
            }
            if(needadd == 1)
            {
                res = "1" + res;
            }
            //reverse(res.begin(),res.end());
        return res;
    }
};
