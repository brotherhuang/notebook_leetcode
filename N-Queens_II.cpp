/* Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/
class Solution {
public:
    int res;
    bool isValid(vector<int> Que, int r){
        for (int i=0;i<r;i++){
            if ( (Que[i]==Que[r])||(abs(Que[i]-Que[r])==(r-i))){
                return false;
            }
        }
        return true;
    }
    void nqueens(vector<int> Que, int cur, int n){
        if (cur==n){ res++;return;}
        else{
            for (int i=0;i<n;i++){
                Que[cur]=i;
                if (isValid(Que,cur)){
                    nqueens(Que,cur+1,n);
                }
            }
        }
    }
    int totalNQueens(int n) {
        res=0;
        vector<int> Que(n,0);
        nqueens(Que,0,n);
        return res;
    }
};
