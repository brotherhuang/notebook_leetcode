/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
] */
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> currentNodeLevel;
        currentNodeLevel.push_back(root);
        while(currentNodeLevel.size() > 0){
              vector<TreeNode*> nextNodeLevel;
              vector<int> currentNodeVale;
              for(int i = 0; i < currentNodeLevel.size(); i++){
                  if(currentNodeLevel[i]){
                      currentNodeVale.push_back(currentNodeLevel[i]->val);
                      if(currentNodeLevel[i]->left){
                          nextNodeLevel.push_back(currentNodeLevel[i]->left);
                      }
                      if(currentNodeLevel[i]->right){
                          nextNodeLevel.push_back(currentNodeLevel[i]->right);
                      }
                  }
              }
              currentNodeLevel = nextNodeLevel;
              if(currentNodeVale.size() > 0){
                  res.push_back(currentNodeVale);
              }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
