/* Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2]. */
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
     vector<int> inorderTraversal(TreeNode* root) {
         vector<int> res;
         vector<TreeNode*> nodeList;
         TreeNode* current = root;
         while(!nodeList.empty() || current != NULL){
            if(current != NULL){
                nodeList.push_back(current);
                current = current->left;
            }
            else{
                current = nodeList.back();
                nodeList.pop_back();
                res.push_back(current->val);
                current = current->right;
            }
         }
         return res;
     }
 };

/* --------------------------------------------*/

class Solution {
public:
    void inorder(TreeNode* node, vector<int>& res){
        if(node){
            if(node->left){
                inorder(node->left,res);
            }
            res.push_back(node->val);
            if(node->right){
                inorder(node->right,res);
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
