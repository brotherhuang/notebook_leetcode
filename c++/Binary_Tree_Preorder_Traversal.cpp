/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].*/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* current = root;
        if(current == NULL) return res;
        vector<TreeNode*> nodeList;
        nodeList.push_back(current);
        while(!nodeList.empty()){
            current = nodeList.back();
            nodeList.pop_back();
            res.push_back(current->val);
            if(current->right != NULL) nodeList.push_back(current->right);
            if(current->left != NULL) nodeList.push_back(current->left);
        }
        return res;
    }
};


/*----------------------------------*/

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res){
        if(!root) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};



class Solution {
public:
    void preorder(TreeNode* node, vector<int>& res){
         if(node){
             res.push_back(node->val);
             if(node->left){
                 preorder(node->left,res);
             }
             if(node->right){
                 preorder(node->right,res);
             }
         }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};
