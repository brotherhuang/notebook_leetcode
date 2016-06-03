/* Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)". */
class Solution {
public:
     string num2str(long a){
        if (a<0){a = -a;}
        ostringstream os;
        os << a;
        return os.str();
    }


    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0 || denominator == 0){
            return "0";
        }
        bool pos=true;
        if ((numerator<0 && denominator>0)||(numerator>0 && denominator<0)){
            pos = false;
        }

        long numer = abs(numerator);
        long denom = abs(denominator);

        int l = -1;
        vector<string> res;
        int maxlen = 1000;
        vector<string> mod;

        while (mod.size()<maxlen){
            res.push_back(num2str(numer / denom));
            long m = numer % denom;
            if (m == 0){
                break;
            }

            for (int i=0;i<mod.size();i++){
                if (mod[i] == num2str(m)){
                    l = i;
                    break;
                }
            }

            if (l == -1){
                mod.push_back(num2str(m));
                numer = m * 10;
            }else{
                break;
            }
        }


        string r = "";

        if (res.size()==1){
            r = res[0];
        }else{
            r=res[0]+".";
            for (int i=1;i<res.size();i++){
                if (i == l+1){
                    r += "(";
                }
                r += res[i];
            }
            if (l != -1){
                r += ")";
            }
        }


        if (pos) {
            return r;
        }else{
            return "-"+r;
        }
    }
};
