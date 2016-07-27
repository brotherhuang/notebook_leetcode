/* Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6. */
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
    int maxPathSum(TreeNode* root) {
        int maxAcrossRoot=INT_MIN;
        int maxEndByRoot = getMax(root, maxAcrossRoot);
        return max(maxAcrossRoot, maxEndByRoot);
    }
    int getMax(TreeNode *node, int& maxAcrossRoot){
        if(node == NULL) return 0;
        int left = getMax(node->left, maxAcrossRoot);
        int right = getMax(node->right, maxAcrossRoot);
        int cMax = node->val;
        if(left>0) cMax+=left;
        if(right>0) cMax+=right;
        maxAcrossRoot = max(maxAcrossRoot, cMax);
        return max(node->val, max(node->val+left, node->val+right));
    }
};
