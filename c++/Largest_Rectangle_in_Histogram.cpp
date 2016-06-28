/* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10. */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            if(i + 1 < heights.size() && heights[i] <= heights[i+1]) continue;
            int minHeight = INT_MAX;
            for(int j = i; j > -1; j--){
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea,minHeight*(i-j+1));
            }
        }
        return maxArea;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        vector<int> s;
        heights.push_back(0);
        int sum = 0;
        int i = 0;
        while(i < heights.size()) {
            if(s.empty() || heights[i] > heights[s.back()]) {
                s.push_back(i);
                i++;
            } else {
                int t = s.back();
                s.pop_back();
                sum = max(sum, heights[t] * (s.empty() ? i : i - s.back() - 1));
            }
        }
        return sum;
    }
};
