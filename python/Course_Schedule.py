"""
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
"""
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        mp = []
        for i in range(numCourses):
            mp.append([] * numCourses)
        finished = [0] *numCourses
        for pre in prerequisites:
            if mp[pre[1]].count(pre[0]) == 0 :
                mp[pre[1]].append(pre[0])
                finished[pre[0]] += 1
        possible = []
        nCourse = 0
        for i in range(numCourses):
            if finished[i] == 0 :
                possible.append(i)
        while possible:
            current = possible.pop()
            nCourse += 1
            for i in mp[current] :
                finished[i] -= 1
                if finished[i] == 0:
                    possible.append(i)
        return nCourse == numCourses    
