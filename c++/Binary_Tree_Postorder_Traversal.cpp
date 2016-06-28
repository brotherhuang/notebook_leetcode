/* Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1]. */
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
    void posorder(TreeNode* node, vector<int>& res){
        if(node){
            if(node->left){
                posorder(node->left,res);
            }
            if(node->right){
                posorder(node->right,res);
            }
            res.push_back(node->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        posorder(root,res);
        return res;
    }
};
