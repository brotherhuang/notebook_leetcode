/* You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        vector<int> stepSize(n,0);
        stepSize[0]  =1;
        stepSize[1] = 2;
        for(int i = 2; i < n; i++){
            stepSize[i] = stepSize[i - 1] + stepSize[i - 2];
        }
        return stepSize.back();
    }
};
