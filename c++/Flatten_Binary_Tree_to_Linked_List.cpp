/* Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6 */

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
     TreeNode* flattenBT(TreeNode* root) {
         if(!root) return NULL;
         TreeNode *leftTail = flattenBT(root->left);
         TreeNode *rightTail = flattenBT(root->right);
         if(root->left) {
             TreeNode *temp = root->right;
             root->right = root->left;
             root->left = NULL;
             leftTail->right = temp;
         }
         if(rightTail) return rightTail;
         if(leftTail) return leftTail;
         return root;
     }
     void flatten(TreeNode* root) {
          TreeNode* rightTail = flattenBT(root);
          root = rightTail;
     }
 };
