/*Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1 */

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){ return NULL;}
        TreeNode* res = new TreeNode(root->val);
        if(root->left){
            res->right = invertTree(root->left);
        }
        else
        {
            res->right = NULL;
        }
        if(root->right){
            res->left = invertTree(root->right);
        }
        else
        {
            res->left = NULL;
        }
        return res;
    }
};
