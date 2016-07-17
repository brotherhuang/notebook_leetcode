/* You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]). */
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
       int res = 0, n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


class Solution {
public:
    int getMaxDepth(int node, vector<vector<bool>> mp, vector<int>& depth){
        if(depth[node] > 0) return depth[node];
        int maxDepth = 1;
        for(int i = 0; i < mp[node].size(); i++){
            if(i != node && mp[node][i]){
                maxDepth = max(maxDepth, getMaxDepth(i, mp, depth) + 1);
            }
        }
        depth[node] =  maxDepth;
        return depth[node];
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<vector<bool>> mp(envelopes.size(), vector<bool>(envelopes.size(), false));
        for(int i = 0; i < envelopes.size(); i++){
            for(int j = 0; j < envelopes.size(); j++){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
                    mp[i][j] = true;
                }
            }
        }
        vector<int> depth(envelopes.size(), 0);
        int maxdepth = 0;
        for(int i = 0; i < envelopes.size(); i++){
            maxdepth = max(maxdepth, getMaxDepth(i, mp, depth));
        }
        return maxdepth;
    }
};
