/*  Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ. */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> currentNodeLevel;
        currentNodeLevel.push_back(root);
        bool leftFirst = true;
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
                  if(!leftFirst) reverse(currentNodeVale.begin(), currentNodeVale.end());
                  res.push_back(currentNodeVale);
                  leftFirst = !leftFirst;
              }
        }
        return res;
    }
};
