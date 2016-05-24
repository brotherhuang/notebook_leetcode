/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit. */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int currentMin = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
           currentMin = (prices[i] < currentMin) ? prices[i]:currentMin;
           maxPro = (maxPro < prices[i] - currentMin)?prices[i] - currentMin:maxPro;
        }
        return maxPro;
    }
};
