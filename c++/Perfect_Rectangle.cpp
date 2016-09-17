/* Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other. */
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT_MAX;
        int right = -1;
        int top = -1;
        int buttom = INT_MAX;
        int toalArea = 0;
        map<pair<int,int>, int> mp;
        set<pair<int,int>> boundary;
        for(int i = 0; i < rectangles.size(); i++){
            buttom = min(buttom, rectangles[i][0]);
            left = min(left, rectangles[i][1]);
            top = max(top, rectangles[i][2]);
            right = max(right, rectangles[i][3]);
            pair<int,int> p0(rectangles[i][0],rectangles[i][1]);
            pair<int,int> p1(rectangles[i][2],rectangles[i][3]);
            pair<int,int> p2(rectangles[i][0],rectangles[i][3]);
            pair<int,int> p3(rectangles[i][2],rectangles[i][1]);
            mp[p0]++;
            mp[p1]++;
            mp[p2]++;
            mp[p3]++;
            toalArea += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        }
        if(toalArea != (right - left) * (top - buttom)) return false;
        boundary.insert(pair<int,int>(buttom, left));
        boundary.insert(pair<int,int>(buttom, right));
        boundary.insert(pair<int,int>(top, left));
        boundary.insert(pair<int,int>(top,right));
        for(auto it = boundary.begin(); it != boundary.end(); ++it){
            if(mp[*it] != 1) return false;
        }
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(boundary.find(it->first) == boundary.end() && it->second % 2 != 0) return false;
        }
        return true;
    }
};
