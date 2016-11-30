/* Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"] */
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
     vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> res;
         stack<TreeNode*> nodeList;
         TreeNode* current = root;
         stack<string> pathStack;
         string path;
         while(!nodeList.empty() || current){
             if(current){
                 nodeList.push(current);
                 if(current == root) path = to_string(current->val);
                 else path = path + "->" + to_string(current->val);
                 if(!current->left && !current->right) res.push_back(path);
                 current = current->left;
                 pathStack.push(path);
             }
             else{
                 current = nodeList.top();
                 nodeList.pop();
                 path = pathStack.top();
                 pathStack.pop();
                 current = current->right;
             }
         }
         return res;
     }
 };
 
 /*---------------------*/

class Solution {
public:
    void pathtoRoot(TreeNode* root, string path, vector<string> &res){
        if(!root) return;
        if(path.size() != 0){
            path = path + "->" + to_string(root->val);
        }
        else{
           path += to_string(root->val);
        }
        if(!root->left && !root->right){
            if(path.size() != 0){
              res.push_back(path);
            }
        }
        pathtoRoot(root->left,path,res);
        pathtoRoot(root->right,path,res);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
	    vector<string> res;
        string path;
        pathtoRoot(root,path,res);
        return res;
    }
};
