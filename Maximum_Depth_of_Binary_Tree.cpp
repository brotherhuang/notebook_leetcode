/* Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) {return 0;}
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};
