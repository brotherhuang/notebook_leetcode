/* Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int L = matrix[0][0], R = matrix[n - 1][n - 1] + 1;
		while (L < R) {
			int mid = L + ((R - L) >> 1);
			int temp = 0;
			for (int i = 0; i < n; i++) temp += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
			if (temp < k) L = mid + 1;
			else R = mid;
		}
		return L;
    }
};
