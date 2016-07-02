/* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode*> currentLevelNode;
        currentLevelNode.push_back(root);
        while(currentLevelNode.size()){
            vector<int> currentLevelValue;
            vector<TreeNode*> nextLevelNode;
            for(int i = 0; i < currentLevelNode.size(); i++){
                currentLevelValue.push_back(currentLevelNode[i]->val);
                if(currentLevelNode[i]->left) nextLevelNode.push_back(currentLevelNode[i]->left);
                if(currentLevelNode[i]->right) nextLevelNode.push_back(currentLevelNode[i]->right);
            }
            res.push_back(currentLevelValue);
            currentLevelNode = nextLevelNode;
        }
        return res;
    }
};


/*-----------------------------------*/
