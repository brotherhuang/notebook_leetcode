/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bulidTree(vector<int>nums, int start, int end){
        if(start > end){return NULL;}
        if(start == end) {return new TreeNode(nums[start]);}
        int mid = start + (end - start)/2;
        TreeNode* midNode = new TreeNode(nums[mid]);
        midNode->left = bulidTree(nums,start,mid-1);
        midNode->right = bulidTree(nums, mid+1, end);
        return midNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bulidTree(nums, 0, nums.size()-1);
    }
};