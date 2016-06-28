/* There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give? */
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> lc(ratings.size(),1);
        vector<int> rc(ratings.size(),1);
        int res=0;
        for (int i=1;i<lc.size();i++){
            if (ratings[i]>ratings[i-1]){
                lc[i]=lc[i-1]+1;
            }
        }
        for (int i=rc.size()-2;i>=0;i--){
            if (ratings[i]>ratings[i+1]){
                rc[i]=rc[i+1]+1;
            }
        }
        for (int i=0;i<ratings.size();i++){
            res+=max(lc[i],rc[i]);
        }
        return res;
    }
};
