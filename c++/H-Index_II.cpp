/* Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm? */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start = 0;
        int end = citations.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(citations[mid] == citations.size() - mid) return citations.size() - mid;
            else if(citations[mid] > citations.size() - mid){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return citations.size() - start;
    }
};
