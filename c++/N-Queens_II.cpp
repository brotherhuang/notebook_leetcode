/* Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/
class Solution {
public:
    void findSolution(int n, vector<int> pos, int row, int& res){
        if(pos.size() == n){
            res++;
        }
        for(int i  = 0; i < n; i++){
            bool valid = true;
            for(int j = 0; j < pos.size(); j++){
                if(i == pos[j] || abs(i - pos[j]) == row - j){
                    valid = false;
                    break;
                }
            }
            if(valid){
                pos.push_back(i);
                findSolution(n,pos,row + 1, res);
                pos.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos;
        findSolution(n,pos,0,res);
        return res;
    }
};
