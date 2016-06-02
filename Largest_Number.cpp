/* Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer. */
class Solution {
public:
    static bool _comp(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);
        sa = sa + sb;
        sb = sb + sa;
        if (sa.compare(sb) >=0){
            return true;
        }else{
            return false;
        }

    }
    string largestNumber(vector<int>& nums) {
        string res="";
        sort(nums.begin(),nums.end(), _comp);
        if (nums[0]==0){return "0";}
        for(int i=0;i<nums.size();i++){
            res = res+ to_string(nums[i]);
        }
        return res;
    }
};
