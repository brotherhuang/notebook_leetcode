/* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int leftGas = 0;
        int minIndex = -1;
        int minLeft = INT_MAX;
        for(int i = 0; i < gas.size(); i++){
            leftGas += (gas[i] - cost[i]);
            minIndex = minLeft > leftGas ? i:minIndex;
            minLeft = minLeft > leftGas ? leftGas:minLeft;
        }
        if(leftGas >= 0){
            return (minIndex + 1) % gas.size();
        }
        else return -1;
    }
};
