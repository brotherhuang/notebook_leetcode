/* Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL */

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
