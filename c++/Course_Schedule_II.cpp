/* There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3]. */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int plen = prerequisites.size();
        vector<int> ind(numCourses, 0);
        vector<vector<bool>> mp(numCourses, vector<bool>(numCourses, false));
        for(int i = 0; i < plen; i++){
            if(mp[prerequisites[i].first][prerequisites[i].second] == false){
                mp[prerequisites[i].first][prerequisites[i].second] = true;
                ind[prerequisites[i].first]++;
            }
        }
        stack<int> course;
        vector<int> order;
        for(int i = 0; i < numCourses; i++){
            if (ind[i]==0) course.push(i);
        }
        while(!course.empty()){
            int current = course.top();
            course.pop();
            order.push_back(current);
            for(int i = 0; i < mp[current].size(); i++){
                if(mp[i][current]){
                    ind[i]--;
                    if(ind[i] == 0){
                        course.push(i);
                    }
                }
            }
        }
        if(order.size() == numCourses){
            return order;
        }
        order.clear();
        return order;
    }
};
