/* Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k && m[nums[j]] == j) m.erase(nums[j++]);
            auto a = m.lower_bound(nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};


class Solution {
public:
    static bool compareHelp(pair<long,long> p0, pair<long,long> p1) {
        return p0.first < p1.first;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long,long>> pairlist;
        for(int i = 0; i < nums.size(); i++){
            pairlist.push_back(pair<long,long>(nums[i],i));
        }
        sort(pairlist.begin(), pairlist.end(), compareHelp);
        for(int i = 0; i < pairlist.size(); i++){
            long j = i + 1;
            while(j < pairlist.size() && pairlist[j].first - pairlist[i].first <= t){
                long diff = pairlist[j].second - pairlist[i].second;
                if(abs(diff) <= long(k)) return true;
                j++;
            }
        }
        return false;
    }
};
