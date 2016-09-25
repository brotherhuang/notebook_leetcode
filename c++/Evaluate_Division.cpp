/* Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction. */
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_set<string> allPossible;
        for(int i = 0; i < equations.size(); i++){
            allPossible.insert(equations[i].first);
            allPossible.insert(equations[i].second);
        }
        int inputSize = equations.size();
        for(int i = 0; i < inputSize; i++){
            equations.push_back(pair<string, string>(equations[i].second, equations[i].first));
            values.push_back(1.0/values[i]);
        }
        vector<double> res;
        for(int i = 0; i < queries.size(); i++){
            string start = queries[i]. first;
            string end = queries[i]. second;
            if(allPossible.find(start) == allPossible.end() || allPossible.find(end) == allPossible.end()){
                res.push_back(-1.0);
            }
            else if(start.compare(end) == 0) res.push_back(1.0);
            else{
                double current = 1.0;
                vector<vector<string>> dfs;
                unordered_set<string> used;
                vector<string> firstLevel = {start};
                dfs.push_back(firstLevel);
                used.insert(start);
                bool found = false;
                while(!found){
                    vector<string> nextLevel;
                    for(int ii = 0; ii < dfs.back().size(); ii++){
                        for(int k = 0; k < equations.size(); k++){
                            if(equations[k].first.compare(dfs.back()[ii]) == 0 && used.find(equations[k].second) == used.end()){
                                nextLevel.push_back(equations[k].second);
                                if(equations[k].second.compare(end) == 0) {
                                    found = true;
                                }
                            }
                        }
                    }
                    if(found || nextLevel.size() == 0) break;
                    dfs.push_back(nextLevel);
                }
                if(!found) {
                    res.push_back(-1.0);
                    continue;
                }
                string currentEnd = end;
                while(dfs.size() > 0){
                    vector<string> currentLevel = dfs.back();
                    dfs.pop_back();
                    bool checked = false;
                    for(int ii = 0; ii < currentLevel.size(); ii++){
                        if(checked) break;
                        for(int k = 0; k < equations.size(); k++){
                             if(equations[k].first.compare(currentLevel[ii]) == 0 && equations[k].second.compare(currentEnd) == 0 ){
                                 current *= values[k];
                                 currentEnd = equations[k].first;
                                 checked = true;
                                 break;
                             }
                         }
                    }
                }
                res.push_back(current);
            }
        }
        return res;
    }
};
