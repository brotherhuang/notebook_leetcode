/* Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& count, int boundaryX, int boundaryY){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> checked(m, vector<bool>(n,false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!checked[i][j] && (i == boundaryX || j == boundaryY)){
                    vector<pair<int, int>> checkList;
                    checkList.push_back(pair<int, int>(i,j));
                    checked[i][j] = true;
                    while(!checkList.empty()){
                        int cX = checkList.back().first;
                        int cY = checkList.back().second;
                        checkList.pop_back();
                        count[cX][cY] ++;
                        if(cX - 1>= 0 && !checked[cX - 1][cY] && matrix[cX][cY] <= matrix[cX-1][cY]) {
                            checkList.push_back(pair<int, int>(cX-1,cY));
                            checked[cX - 1][cY] = true;
                        }
                        if(cX + 1 < m && !checked[cX + 1][cY] && matrix[cX][cY] <= matrix[cX+1][cY]){
                            checkList.push_back(pair<int, int>(cX+1,cY));
                            checked[cX + 1][cY] = true;
                        }
                        if(cY > 0 && !checked[cX][cY-1] && matrix[cX][cY] <= matrix[cX][cY-1]){
                            checkList.push_back(pair<int, int>(cX,cY-1));
                            checked[cX][cY-1] = true;
                        }
                        if(cY + 1 < n && !checked[cX][cY+1] && matrix[cX][cY] <= matrix[cX][cY+1]){
                           checkList.push_back(pair<int, int>(cX,cY+1));
                           checked[cX][cY+1] = true;
                        }
                    }

                }
            }
        }

    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        vector<vector<int>> count(m, vector<int>(n,0));
        dfs(matrix, count, 0,0);
        dfs(matrix, count, m-1, n-1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(count[i][j] == 2) res.push_back(pair<int, int>(i,j));
            }
        }
        return res;
    }
};
