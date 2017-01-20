class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        vector<char> sNew;
        for(auto s : S){
            if(s != '-') sNew.push_back(s);
        }
        int currentKey = sNew.size() % K;
        string res;
        for(auto s : sNew){
           if(currentKey == 0){
                    currentKey = K;
                    if(res.size() != 0)  res.push_back('-');
                }
            if(s - 'a' >=0 && s - 'z' <=0) res.push_back(s - 'a' + 'A');
            else res.push_back(s);
            currentKey--;
        }
        return res;
    }
};
