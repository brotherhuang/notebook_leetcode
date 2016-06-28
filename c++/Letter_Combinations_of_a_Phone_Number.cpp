/* Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]. */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
      unordered_map<int, vector<string>> mp;
      mp[0] = {"  "}; mp[1] = {" "};mp[2] = {"a","b","c"};
      mp[3] = {"d","e","f"};mp[4] = {"g","h","i"};mp[5] = {"j","k","l"};
      mp[6] = {"m","n","o"};mp[7] = {"p","q","r","s"};mp[8] = {"t","u","v"};mp[9] = {"w","x","y","z"};
      vector<string> res;
      if(digits.size() == 0) return res;
      int totalCombinations = 1;
      vector<int> accuProd;
      for(int i =0; i < digits.size(); i++){
             int dig = digits[i] - '0';
             totalCombinations *= (mp[dig].size());
             accuProd.push_back(totalCombinations);
         }
      for(int i = 0; i < accuProd.size(); i++){
            accuProd[i] = totalCombinations /accuProd[i];
        }
      for(int i =0; i < totalCombinations; i++){
          string lc;
          int currentSize = i;
          int valueIndex = 0;
          for(int j = 0; j < digits.size(); j++){
              int dig = digits[j] - '0';
              int currentNum = currentSize / accuProd[valueIndex];
              lc = lc + mp[dig][currentNum];
              currentSize = currentSize % accuProd[valueIndex];
              valueIndex++;
          }
          res.push_back(lc);
      }
      return res;
    }
};
