/* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
] */
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
    void findPath(TreeNode* root, int target, vector<int>ress, vector<vector<int>> &res){
        if(!root) return ;
        if(!root->left && !root->right && target == root->val){
            ress.push_back(root->val);
            res.push_back(ress);
        }
        if(root->left){
            ress.push_back(root->val);
            findPath(root->left, target -root->val, ress,res);
            ress.pop_back();
        }
        if(root->right){
            ress.push_back(root->val);
            findPath(root->right, target -root->val, ress,res);
            ress.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> ress;
        findPath(root, sum, ress,res);
        return res;
    }
};
