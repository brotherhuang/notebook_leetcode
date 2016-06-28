/* Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        for(int  i = 1; i < prices.size(); i++){
            int diff = prices[i] - prices[i-1];
            if(diff > 0){
                prof += diff;
            }
        }
        return prof;
    }
};
