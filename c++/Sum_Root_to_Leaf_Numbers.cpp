/* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.*/
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
    void calculatePath(TreeNode* root, int currentPath, int &sum){
        if(!root){
            sum += currentPath;
            return;
        }
        currentPath = currentPath * 10 + root->val;
        if(root->left){
            calculatePath(root->left, currentPath, sum);
        }
        if(root->right){
            calculatePath(root->right, currentPath, sum);
        }
        if(!root->left && !root->right){
            sum += currentPath;
        }
    }
    int sumNumbers(TreeNode* root) {
        int total = 0;
        int path = 0;
        calculatePath(root, path, total );
        return total;
    }
};
