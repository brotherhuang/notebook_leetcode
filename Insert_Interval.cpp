/* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 /**
  * Definition for an interval.
  * struct Interval {
  *     int start;
  *     int end;
  *     Interval() : start(0), end(0) {}
  *     Interval(int s, int e) : start(s), end(e) {}
  * };
  */
 class Solution {
 public:
     vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
         vector<Interval> res;
         int startPos = -1;
         int endPos = -1;
         bool isStartInside = false;
         bool isEndInside = false;
         for(size_t i= 0; i < intervals.size(); i++){
             if(newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) isStartInside = true;
             if(newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) isEndInside = true;
             if(newInterval.start >= intervals[i].start) startPos++;
             if(newInterval.end >= intervals[i].start) endPos++;
         }

         if(isStartInside) {
             for(int i = 0; i < startPos; i++) res.push_back(intervals[i]);
             newInterval.start = intervals[startPos].start;
         }
         else {
             for(int i = 0; i <= startPos; i++) res.push_back(intervals[i]);
         }
         if(isEndInside){
             newInterval.end = intervals[endPos].end;
         }
         res.push_back(newInterval);
         for(int i = endPos + 1; i < intervals.size(); i++) res.push_back(intervals[i]);
         return res;
     }
 };

 

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int startPos = -1;
        int endPos = -1;
        bool isStartInside = false;
        bool isEndInside = false;
        for(size_t i= 0; i < intervals.size(); i++){
            if(newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) isStartInside = true;
            if(newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) isEndInside = true;
            if(newInterval.start >= intervals[i].start) startPos++;
            if(newInterval.end >= intervals[i].start) endPos++;
        }
        if(isStartInside && isEndInside) {
            for(int i = 0; i < startPos; i++) res.push_back(intervals[i]);
            Interval newInterval(intervals[startPos].start,intervals[endPos].end); res.push_back(newInterval);
            for(int i = endPos + 1; i < intervals.size(); i++) res.push_back(intervals[i]);
        }
        if(!isStartInside && isEndInside){
            for(int i = 0; i <= startPos; i++) res.push_back(intervals[i]);
            Interval newInterval(newInterval.start,intervals[endPos].end); res.push_back(newInterval);
            for(int i = endPos + 1; i < intervals.size(); i++) res.push_back(intervals[i]);
        }
        if(!isStartInside && !isEndInside){
            for(int i = 0; i <= startPos; i++) res.push_back(intervals[i]);
            Interval newInterval(newInterval.start,newInterval.end); res.push_back(newInterval);
            for(int i = endPos + 1; i < intervals.size(); i++) res.push_back(intervals[i]);
        }
        if(isStartInside && !isEndInside){
            for(int i = 0; i < startPos; i++) res.push_back(intervals[i]);
            Interval newInterval(intervals[startPos].start,newInterval.end); res.push_back(newInterval);
            for(int i = endPos + 1; i < intervals.size(); i++) res.push_back(intervals[i]);
        }
        return res;
    }
};
