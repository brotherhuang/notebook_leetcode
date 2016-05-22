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
    void searchTree(TreeNode* root,int k,vector<int> &res){
        if(root->left){
            searchTree(root->left,k,res);
        }
        if(res.size() < k){
            res.push_back(root->val);
        }
        else {
            return ;
        }
        if(root->right){
            searchTree(root->right,k,res);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        searchTree(root,k,res);
        return res.back();
    }
};
