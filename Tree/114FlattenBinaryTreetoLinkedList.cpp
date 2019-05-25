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
    void flatten(TreeNode* root) {
        helper(root, NULL);
    }
    TreeNode* helper(TreeNode* root, TreeNode* pre){
        if(!root) return pre;
        pre = helper(root->right, pre);
        pre = helper(root->left, pre);
        root->right = pre;
        root->left = NULL;
        pre = root;
        return pre;
    }
};