/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3 */

    class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1,0);
        res[0] = 1;
        res[1] = 1;
        for(int i = 2; i < n+1; i++){
            int total = 0;
            for(int j = 1; j <= i; j++){
                total += res[j - 1]*res[i - j];
            }
            res[i] = total;
        }
        return res[n];
    }
};