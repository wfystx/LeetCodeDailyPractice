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
    bool isBalanced(TreeNode* root) {
        int res = helper(root);
        return res != -1;
    }
    int helper(TreeNode* root){
        if(!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        if(l == -1 || r == -1) return -1;
        if(abs(l - r) > 1) return -1;
        return max(l,r) + 1;
    }
};