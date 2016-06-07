/* Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. */
class Solution {
public:
    bool isNumber(string s) {
         int posDot = -1;
         int posE = -1;
         int countDot = 0;
         int countE = 0;
         int statrPos = 0;
         int endPos = s.size() - 1;
         bool containNum = false;
         int posN = -1;
         int lastN = -1;
         while(s[statrPos] == ' ') statrPos++;
         if(s[statrPos] == '-' ||s[statrPos] == '+' ) statrPos++;
         while(s[endPos] == ' ') endPos--;
         for(int i = statrPos; i <= endPos; i++){
             if(s[i] >= '0' && s[i] <= '9') {
                 if(!containNum){
                     containNum = true;
                     posN = i;
                 }
                 lastN = i;
             }
             else if(s[i] == '.' ) {posDot = i; countDot++;}
             else if(s[i] == 'e') {
                 posE = i;
                 countE++;
                 if(s[i+1] == '-' ||s[i+1] == '+' ) i++;
             }
             else return false;
         }
         if(!containNum) return false;
         if(countDot > 1 || countE > 1) return false;
         if(posE != -1 && posE < posDot) return false;
         if(posE != -1 && posE < posN) return false;
         if(lastN < posE) return false;
         return true;
    }
};
