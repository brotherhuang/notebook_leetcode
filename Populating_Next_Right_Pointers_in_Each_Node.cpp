/* Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL */

    /**
     * Definition for binary tree with next pointer.
     * struct TreeLinkNode {
     *  int val;
     *  TreeLinkNode *left, *right, *next;
     *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
     * };
     */
class Solution {
public:
   void connect(TreeLinkNode *root) {
       if(!root) return ;
       if(root->left) root->left->next = root->right;
       if(root->right) root->right->next = root->next == NULL ? NULL:root->next->left;
       connect(root->left);
       connect(root->right);
   }
};     

class Solution {
public:
    void connect(TreeLinkNode *root) {
             if(!root) return ;
             vector<TreeLinkNode*> currentLevel;
             currentLevel.push_back(root);
             while(currentLevel.size()){
                 for(int i = 0; i < currentLevel.size() - 1; i++){
                     currentLevel[i]->next = currentLevel[i+1];
                 }
                 currentLevel.back()->next = NULL;
                 vector<TreeLinkNode*> nextLevel;
                 for(int i = 0; i < currentLevel.size(); i++){
                     if(currentLevel[i]->left){
                         nextLevel.push_back(currentLevel[i]->left);
                     }
                     if(currentLevel[i]->right){
                         nextLevel.push_back(currentLevel[i]->right);
                     }
                 }
                 currentLevel = nextLevel;
             }
    }
};
