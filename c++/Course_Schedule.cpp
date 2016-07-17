/* There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible. */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int plen = prerequisites.size();
        vector<int> ind(numCourses,0);
        vector<vector<bool> > map(numCourses, vector<bool>(numCourses, false));
        for (int i=0;i<plen;i++){
            if (map[prerequisites[i].first][prerequisites[i].second] == false){
                map[prerequisites[i].first][prerequisites[i].second] = true;
                ind[prerequisites[i].first]++;
            }
        }
        stack<int> st;
        for (int i=0;i<numCourses;i++){
            if (ind[i]==0) st.push(i);
        }
        int count = 0;
        while (!st.empty()){
            int tmp = st.top();
            st.pop();
            count ++;
            for (int i=0;i<numCourses;i++){
                if (map[i][tmp]){
                    ind[i]--;
                    if (ind[i]==0) st.push(i);
                }
            }
        }
        return count < numCourses ? false : true;
    }
};
