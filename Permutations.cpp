/* Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. */
class Solution {
public:
       void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
        if (k==n){
            res.push_back(num);
        }else{
            for (int i=k;i<=n;i++){
                int tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
                perm(num,k+1,n,res);
                tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        perm(num,0,(num.size()-1),res);
        return res;
    }
};
