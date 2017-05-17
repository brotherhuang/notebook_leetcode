class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            else if (nums[mid] == nums[mid-1]){
                if(mid % 2 == 0) end = mid - 2;
                else start = mid + 1;
            }
            else{
                if(mid % 2 == 0) start = mid + 2;
                else end = mid - 1;
            }
        }
        return nums[start];
    }
};
