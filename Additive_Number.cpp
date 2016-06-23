/* Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid. */
class Solution {
public:
    bool validString(string first, string second, string num){
        int startCheck = first.size() + second.size();
        if(startCheck == num.size()) return false;
        while(startCheck < num.size()){
            string next = to_string(stoll(first) + stoll(second));
            for(int i = 0 ; i < next.size(); i++){
                if(next[i] != num[startCheck + i]) return false;
            }
            startCheck += next.size();
            first = second;
            second = next;
        }
        return true;

    }
    bool isAdditiveNumber(string num) {
         for(int i = 0; i < num.size(); i++){
             string first = num.substr(0, i + 1);
             if(first[0] == '0' && first.size() > 1) continue;
             for(int j = i + 1; j < num.size(); j++){
                 string second = num.substr(i + 1, j - i);
                 if(second[0] == '0' && second.size() > 1) continue;
                 if(validString(first, second, num)) return true;
             }
         }
         return false;
    }
};
