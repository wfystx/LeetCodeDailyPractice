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
    int cnt = 0;
    int res = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        helper(root);
        return res;
    }
    void helper(TreeNode* root){
        if(root->left) helper(root->left);
        cnt -= 1;
        if(cnt == 0){
            res = root->val;
            return;
        }
        if(root->right) helper(root->right);
    }
};