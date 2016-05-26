/* Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4]. */
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if(!root){return rightView;}
        vector<TreeNode*> currentNodeLevel;
        currentNodeLevel.push_back(root);
        while(currentNodeLevel.size() > 0){
              vector<TreeNode*> nextNodeLevel;
              for(int i = 0; i < currentNodeLevel.size(); i++){
                  if(currentNodeLevel[i]){
                      if(currentNodeLevel[i]->left){
                          nextNodeLevel.push_back(currentNodeLevel[i]->left);
                      }
                      if(currentNodeLevel[i]->right){
                          nextNodeLevel.push_back(currentNodeLevel[i]->right);
                      }
                  }
              }
              if(currentNodeLevel.back()){
                 rightView.push_back(currentNodeLevel.back()->val);
              }
              currentNodeLevel = nextNodeLevel;
        }
        return rightView;
    }
};
