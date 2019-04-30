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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rev;
        helper(root, rev);
        return rev;
    }
    void helper(TreeNode* root, vector<int> &rev){
        if(root==NULL) return;
        else{
            rev.push_back(root->val);
            helper(root->left, rev);
            helper(root->right, rev);
        }
    }
};