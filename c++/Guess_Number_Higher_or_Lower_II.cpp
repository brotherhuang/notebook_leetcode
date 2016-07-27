/*We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Show Hint  */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i = 0;i<n;i++) dp[i][i] = 0;
        for(int len = 2;len<=n;len++){
            for(int i = 0;i+len-1<n;i++){
                int j = i+len-1;
                for(int k = i;k<=j;k++){
                    if(k == i){
                        dp[i][j] = min(dp[i][j],dp[k+1][j]+k+1);
                    }else if(k == j){
                        dp[i][j] = min(dp[i][j],dp[i][k-1]+k+1);
                    }else{
                        dp[i][j] = min(dp[i][j],max(dp[i][k-1],dp[k+1][j])+k+1);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
