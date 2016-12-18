/*
Given inorder and postorder traversal of a tree, construct the binary tree.
*/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back());
        stn.push(root);
        postorder.pop_back();

        while(true)
        {
            if(inorder.back() == stn.top()->val)
            {
                p = stn.top();
                stn.pop();
                inorder.pop_back();
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.push(p->left);
            }
            else
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p;
                stn.push(p);
            }
        }
        return root;
    }
};
