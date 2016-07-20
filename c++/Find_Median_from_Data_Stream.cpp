/* Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2 */
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> maxHalf;
    priority_queue<int, vector<int>, greater<int>> minHalf;
    // Adds a number into the data structure.
    void addNum(int num) {
        maxHalf.push(num);
        int t = maxHalf.top();
        maxHalf.pop(); minHalf.push(t);
        int m = maxHalf.size(), n = minHalf.size();
        if (n > m) {
            int t = minHalf.top();
            minHalf.pop(); maxHalf.push(t);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int m = maxHalf.size(), n = minHalf.size();
        if (!m && !n) return 0.0;
        if (m == n) return (maxHalf.top() + minHalf.top()) / 2.0;
        return (m > n) ? maxHalf.top() : minHalf.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
