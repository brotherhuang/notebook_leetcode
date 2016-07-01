/* Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) */
class Solution {
public:
    void getValid(string s, int startPos, int currentSize, string validIP, vector<string>& res){
        if((currentSize == 4 && startPos != s.size()) || (startPos > s.size())) return;
        if(startPos == s.size() && currentSize == 4){
            validIP.pop_back();
            res.push_back(validIP);
        }
        for(int i = 1; i <= 3; i++){
            if(startPos + i <= s.size()){
                string current = s.substr(startPos, i);
                if(i > 1 && current[0] == '0') continue;
                if(stoi(current) <= 255) {
                    validIP = validIP + current + '.';
                    getValid(s,startPos + i, currentSize + 1, validIP, res);
                    for(int  j= 0; j <= i; j++) validIP.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string validIP;
        getValid(s,0,0,validIP,res);
        return res;
    }
};

/*--------------------------------*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for(int i = 1; i <=3; i++){
            for(int j = 1; j <=3; j++){
                for(int k = 1; k <=3; k++){
                    for(int l = 1; l <=3; l++){
                        if( i + j + k + l != s.size()) continue;
                        string p0 = s.substr(0,i);
                        if(stoi(p0) > 255 || (i > 1 && p0[0] == '0')) continue;
                        string p1 = s.substr(i,j);
                        if(stoi(p1) > 255 || (j > 1 && p1[0] == '0')) continue;
                        string p2 = s.substr(i + j,k);
                        if(stoi(p2) > 255 || (k > 1 && p2[0] == '0')) continue;
                        string p3 = s.substr(i + j + k,l);
                        if(stoi(p3) > 255 || (l > 1 && p3[0] == '0')) continue;
                        string validIP = p0 + "." + p1 + "." + p2 + "." + p3;
                        res.push_back(validIP);
                    }
                }
            }
        }
        return res;
    }
};
