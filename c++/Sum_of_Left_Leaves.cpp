/*Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.*/
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
    void findAllleft(TreeNode* root, bool isLeft, int& sum){
        if(!root) return;
        if(isLeft && !root->left && !root->right){
            sum += root->val;
            return;
        }
        findAllleft(root->left, true, sum);
        findAllleft(root->right, false, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        findAllleft(root, true, sum);
        return sum;
    }
};
