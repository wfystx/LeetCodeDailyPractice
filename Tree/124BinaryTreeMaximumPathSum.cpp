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
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return res;
    }
    int helper(TreeNode* root){
        if(!root) return 0;
        int l = max(0, helper(root->left));
        int r = max(0, helper(root->right));
        res = max(l+r+root->val, res);
        return max(l, r) + root->val;
    }
    
};