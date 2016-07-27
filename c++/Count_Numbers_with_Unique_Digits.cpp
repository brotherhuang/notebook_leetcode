/* Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Show Hint
 */

 class Solution {
 public:
     int countNumbersWithUniqueDigits(int n) {
         n = min(n,10);
         vector<int> dp(n + 1, 9);
         dp[0] = 1;
         for(int i = 2;i<=n;i++){
             for(int x = 9; x >= 9 - i + 2;x--){
                 dp[i] *= x;
             }
         }
         int ans = 0;
         for(int i= 0;i<dp.size();i++) ans += dp[i];
         return ans;
     }
 };
