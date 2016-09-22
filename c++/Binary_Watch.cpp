/* A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]*/
class Solution {
public:
    int countBinary(int num){
        int res = 0;
        while(num > 0){
            res += num % 2;
            num /= 2;
        }
        return res;
    }
    vector<string> getHour(int num){
        vector<string> res;
        if(num > 3) return res;
        for(int i = 0; i < 12; i++){
            if(countBinary(i) == num){
                res.push_back(to_string(i));
            }
        }
        return res;
    }
    vector<string> getMin(int num){
        vector<string> res;
        if(num > 6) return res;
        for(int i = 0; i < 60; i++){
            if(countBinary(i) == num){
                res.push_back(to_string(i));
                if(i < 10) res.back() = "0" + res.back();
            }
        }
        return res;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int i = 0; i <= num; i++){
            vector<string> hour = getHour(i);
            vector<string> mins = getMin(num - i);
            for(auto h : hour)
            for(auto m : mins){
                res.push_back(h + ":" + m);
            }
        }
        return res;
    }
};
