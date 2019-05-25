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
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    bool helper(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        if(t1->val != t2->val) return false;
        return helper(t1->left, t2->right) && helper(t1->right, t2->left);
    }
};