/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   */
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
    vector<TreeNode*> generateTreeRange(int start, int end){
        vector<TreeNode*> res;
        if(start > end) res.push_back(NULL);
        else if(start == end) res.push_back(new TreeNode(start));
        else{
            for(int i = start; i <= end ; i++){
                vector<TreeNode*> left = generateTreeRange(start, i-1);
                vector<TreeNode*> right = generateTreeRange(i+1, end);
                for(auto l : left){
                    for(auto r : right){
                        TreeNode* root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n < 1) return res;
        return generateTreeRange(1,n);
    }
};
